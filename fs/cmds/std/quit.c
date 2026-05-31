// quit.c

#include <ansi.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
inherit F_SKILL;
object *inb,horse, pal;
object *inv, link_ob, body_ob, mob, wiz ;
string *gift_key, *my_key, id, src, dst,pktitle;

mapping gift = ([
  "str":"膂力",
  "cor":"膽識",
  "int":"悟性",
  "spi":"靈性",
  "cps":"定力",
  "per":"容貌",
  "con":"根骨",
  "kar":"福緣",
]);

void create()
{
  seteuid(getuid());
  set("name", "離線指令");
  set("id", "quit");
  set_temp("channel_id", "連線精靈");
}

int main(object me, string arg)
{
  mapping my;
int i;
  object env;
  env = environment(me);
  wiz=0;
  if( wizardp(me) && arg ) {
    if( wiz_level(me) < 4 )
      return notify_fail("你的職權無法強迫玩家離開。\n");
    wiz=me;
    if( !(me=find_player(arg)) )
      return notify_fail("沒有這個玩家。\n");
/*
    if( wiz_level(wiz) < wiz_level(me) )
      return notify_fail("你無法強迫上級離開。\n");
*/
  }
  //若有設must_be_quit就一定會被quit,殺人兇手也不例外 by bss
  if(!me->query_temp("must_be_quit"))
  if( me->query("robot/ans") )
    return notify_fail( "你現在正被審問, 不得離線!\n" );

  if (me->query("pker")) {
    //chan設定pker三十分鐘不能離線
    if(me->query("PKTIME") >= time()) //這樣應該就不會有要wiz幫他消殺人兇手title的事by bss
      return notify_fail("你現在是殺人兇手，不能離線！\n");

    //表示超過三十分鐘都沒有事,就不是pker了 by chan
    else {
      me->set("pker",0);
      pktitle=me->query("PKNAME"); //將他的title回復
      me->set("title",pktitle);
      return notify_fail("你現在以經不是殺人兇手了,再打一次quit就可以離線了!\n");
    }
  }

  if (me->query_temp("multipk")) {
    if (!me->query_temp("must_be_quit")) {
      return notify_fail( "尚未繳交武林大會場地費, 無法離線。\n" );
    }
    else {
      "/open/mulitpk/room/room01.c"->valid_leave(me,"out");
    }
  }

  if (me->is_fighting())
    return notify_fail( "您正在戰鬥, 無法離線。\n");
  if (environment(me)->query("no_quit"))
    return notify_fail( "在此處離線不大妥當喔，請移駕安全的地方。\n");
  if (me->query_temp("no_quit"))
    return notify_fail( me->query_temp("no_quit")+"\n");

  if (me->query_temp("搶劫中") || me->query("old_id")) {
    me->delete("greeting_msg");
    me->set("id", me->query("old_id"));
    me->set("name", me->query("old_name"));
    me->set("nickname", me->query("old_nick"));
    me->set("title", me->query("old_title"));
    me->delete("old_id");
    me->delete("old_name");
    me->delete("old_nick");
    me->delete("old_title");
    env->delete("have_bandit");
  }
  if (me->query_temp("募捐中")){
    tell_object(me, HIW"你開始收起破碗公,離開這裡。\n"NOR);
    me->delete("greeting_msg");
    me->set("id", me->query("old_id"));
    me->set("name", me->query("old_name"));
    me->set("nickname", me->query("old_nick"));
    me->set("title", me->query("old_title"));
    me->delete("old_id");
    me->delete("old_name");
    me->delete("old_nick");
    me->delete("old_title");
    me->delete_temp("募捐中");
    me->delete_temp("不准走");
  }

  if(me->query_temp("不准走")) return notify_fail("你現在不準走......!!\n");

  if(!wizardp(me)) {
    me->delete("env/隱身");
  }
/*
  // 重新解後三 by swy
  if (!me->query("mblade-new")) {
    me->set("mblade-new",1);
  }

  // meq and godeq 氾濫所以要查一下 by swy
  if (ob && !me->query("qu-meq")) {
    me->set("qu-meq",1);
    me->delete("meq");
    me->delete("have_mdragon");
    log_file("mblade/meq",sprintf("(%s) 有 meq\n",me->query("id")));
  }

  if (ob2 && !me->query("qu-godeq")) {
    me->set("qu-godeq",1);
    log_file("mblade/godeq",sprintf("(%s) 有 godeq\n",me->query("id")));
  }

  // 發新的有 set 所以以下檢查不用關 by swy
  if (!me->query("new-by-swy") && me->query("id")!="swy" ) {
    me->delete("clear-meq-godeq");
    me->delete("del-meq-godeq");
    inb = all_inventory(me);
    for (j=0; j<sizeof(inb); j++)
      if (inb[j]->query("id")=="mdragon-eq" || inb[j]->query("id")=="god-eq") {
        log_file ("mblade/clear-eq",
                  sprintf ("(%s)清除%s\n", me->query("id"),
                          inb[j]->query("name")));
        destruct(inb[j]);
     }
  }
*/
  if (me->query_temp("have_horse",1)==1) {
    horse = find_living((string)me->query_temp("horse",1));
    if (horse && (horse->query_temp("my_boss",1)==me->query("id",1))) {
      destruct(horse);
    }
  }

    if (me->query("class")=="blademan") {
    me->do_command("enable dodge none");
    me->do_command("enable move none");
    me->reset_action();
  }
  if (me->query("force_factor") > 10)
    me->set("force_factor",10);
  if (me->query("mana_factor") > 10)
    me->set("mana_factor",10);

  //設定離線時enforce 為 10 by chan
  if (me->query("powerup_flag")) {
    me->delete("powerup_flag");
    me->set("force_factor" ,10);
  }

  if (me->query_temp("upforce")==1) me->set("force_factor" ,10);
  gift_key = keys(gift);
  if (me->query_temp("spe") == 1)
    SEC_KEE_D(me->query("sec_kee"))->remove_it(me);

  for (i=0; i<sizeof(gift); i++) {
    if( me->query(gift_key[i])>35 ) {
      tell_object(me,"你的"+gift[gift_key[i]]+"過高﹐系統將它改為 35。\n");
      me->set(gift_key[i],35);
    }
  }

  // 把東西丟下來？
  if (!wizardp(me)) {
    inv = all_inventory(me);
    for (i=0; i<sizeof(inv); i++)
      if (!inv[i]->query_autoload() && inv[i]->query("name") != "布衣")
        DROP_CMD->do_drop(me, inv[i]);
  }

  if( sizeof(me->query_team()) > 0 ) {
    if(me->query_temp("leader"))
      me->query_temp("leader")->dismiss_team();
    write("你脫離了隊伍了\n");
    me->dismiss_team();
  }


  // 這裡是判斷: 如果有人switch mob 的話, 則將link_ob 交回原
  // char身上。這裡是使玩家檔壞的最大原因, 現在已經改好了
  //                                       modified by Konn
  //
  if (body_ob = me->query_temp ("body_ob")) {
    link_ob = me->query_temp ("link_ob");
    me->delete_temp ("body_ob");
    exec (link_ob, me);
    exec (body_ob, link_ob);
    body_ob->setup();
    tell_object (me, "你的魂魄回到"+ body_ob->name() +"的身上。\n");
    write ("ok.\n");
    return 1;
  }

  if (wiz && wizardp(this_player(1))) {
    tell_object(me, wiz->name() + "(" + wiz->query("id") + ")強迫你離線。\n");
    message_vision("$N被$n瞪了一眼就離開遊戲了。\n", me, wiz);
  }

  // by acky
  else {
    me->delete_temp("msg_buffer");
    write( "\n"+
    HIB"  ╓──╖╓──╖╓─╖╖╓╥─╖╓──╖╓──╖╓    ╖\n"+
    BLU"  ╟──╖╟──╢║  ║║  ║    ╟──╢╙──╖║    ║\n"+
    HIC"  ║      ║    ║║  ║║  ║    ║    ║      ║╙─╥╜\n"+
    CYN"  ╙      ╙    ╜╙  ╙╜  ╨    ╙    ╜╙──╜  ─╨  \n"+
    HIB"                                  ╓──╖╓──╮╓──╖╓──╖╓──╖\n"+
    BLU"                                  ╙──╖║    ║╟──╢║      ╟──╖\n"+
    HIC"                                        ║╟──╜║    ║║      ║      \n"+
    HIC"◆"+HIW"────────────────"+CYN"╙──╜╙      ╙    ╜╙──╜╙──╜"+HIW"─"+HIC"◆\n");
    write( CYN"\n由於你對真實世界的牽掛, 你將回到原來的世界。\n" +
           "希望你不要忘了自己的使命和你對這狂想空間夥伴們的承諾。\n"NOR );
    message_vision ("$N離開狂想空間了。\n", me);
  }

  log_file ("quit",
            sprintf("%s(%s)於 %s 離開遊戲。\n他的上一個命令是 '%s'\n",
                    me->query("name"),
                    me->query("id"),
                    ctime(time()),
                    me->query_temp("last_input"))
  );

  // Modify By Spirits. 10.02.1995
  if (wiz_level(me) != 7) {
    CHANNEL_D->do_channel(this_object(), "sys",
      sprintf("%s(%s)離線。", me->query("name"), me->query("id")) );
  }
  me->set("last_on", time());

  if( pal=me->query_temp("pal") ) {
    pal->save();
    destruct(pal);
  }

  me->save();
  foreach(object it in all_inventory())
	destruct(it);
 
  destruct(me);
  return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quit <player>
指令說明 :
           當你(妳)想離開狂想的時候，可利用此一指令。
           離開之前，系統會自動儲存您的進度。
           大巫師則可以強迫玩家離線。
HELP);
        return 1;
}
