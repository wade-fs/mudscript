// wade 重新改過 copy from Eastern.Pig (10.6.1995)

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

void create()
{
  seteuid(getuid());

set("long",@LONG

    這是一件剛出爐的麵包師披風，為了巫師工作方便，巫師們常常需要穿這件披風
    如果巫師們想要有進一步的功能歡迎提供

    本披風寫的並不好, 尤其是訊息的顯示並不一致，
    本物件歡迎大巫師(arch)修改成更完善一點
    但是巫師(wizard)絕對不能有備份, 也就是不能在自己目錄下有備份或修改過的
    也不希望巫師拿來做壞事, 還有, 不可干擾玩家
    否則重則打入十八層地獄，輕則禁足一個月，至於判斷標準由大神(admin)裁奪

    鍵入<help cloak>以獲得更多的資訊。

LONG
);

  set("unit","件");
  set("no_drop", 1);

  set("armor_type", "cape");
  set("light",1);
  setup();
}

void init()
{
	object me = this_player();
  seteuid(geteuid());

  if (me)
    set_name (me->name(1)+ "的麵包師披風", ({ "wiz cloak", "cloak" }));
  else
    set_name ("麵包師披風", ({ "wiz cloak", "cloak" }));

  add_action("help","help");
  add_action("full","full");
  add_action("rem","rem");
  add_action("wave","wave");
  add_action("steal","steal");
  add_action ("whereis", "whereis");
  add_action ("pk_mob", "mobpk");
  add_action ("do_give", "give");
  add_action ("do_wakeup", "wakeup");
  add_action ("force_quit", "fquit");

  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="cloak") return 0;

write(@Help

    本披風寫的並不好, 尤其是訊息的顯示並不一致，
    本物件歡迎大巫師(arch)修改成更完善一點
    但是巫師(wizard)絕對不能有備份, 也就是不能在自己目錄下有備份或修改過的
    也不希望巫師拿來做壞事, 還有, 不可干擾玩家
    否則重則打入十八層地獄，輕則禁足一個月，至於判斷標準由大神(admin)裁奪

    你可以使用以下的幾個命令:

       % localcmd, stat, call, data, score, skills, 等等
         請用 help wizcmds 取得進一步資料

       wave <number> <type>		<<取出哪種錢幣的多少數目>
       rem <eqs> from <object>		<讓某一 object 解除裝備>
       steal <object> from <object>	<從某玩家或object身上拿某樣東東>
       mobpk <生物1> with <生物2>	<讓生物1 與生物2 互 k>
       whereis <玩家>			<顯示一玩家的所在地>
       full <玩家>              	<全醫, 玩家若無輸入則內定為自己>
       wakeup <玩家>			<把昏迷不醒的玩家叫醒>

Help

);

  return 1;
}

int rem(string str)

{
  string ob,player;
  object obj,npc;
  seteuid(geteuid());

  sscanf(str,"%s from %s",ob,player);

  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("[cloak]: 沒這個人\n");
  
  obj=present(ob, npc);

  if(!obj)
    return notify_fail ("這裡沒有那種東東\n");
  else {
    message_vision ("$N讓$n脫下"+ob+"\n", this_player(), obj);
    obj->move(this_player());
    obj->move(npc);
    return 1;
  }
}

int steal (string str)
{
  string ob,player;
  object obj, npc, me;

  seteuid(geteuid());

  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  npc = find_player (player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("沒這個"+str+"\n");
   if(wiz_level(npc)>4) return notify_fail("想偷大神的東西﹐下輩子吧。\n");
  if (!(obj=present(ob, npc)))
    return notify_fail ("沒這個東西: "+ob+".\n");

  obj->move(me);

  message_vision ("$N偷了"+npc->query("name")+"的"+ob+"\n", me);
  log_file("wiz/steal_player", sprintf("%s(%s) steal %s(%s)'s %s on %s\n",
  me->name(1),geteuid(me),npc->name(1),geteuid(npc),file_name(obj),ctime(time())  ));

  return 1;
}

int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在虛無飄藐間。\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[cloak]: full error: 找不到"+str+"\n");
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("force",me->query("max_force"));
  me->set("eff_kee",max);
  me->set("atman",me->query("max_atman"));
  me->set("mana",me->query("max_atman"));
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();

  message_vision( sprintf("$N唸起不死族回復咒文 [32;1m撒拉 伊克 庵修姆[37;0m  \n"),
                  this_player());
  if( this_player() != me ) 
  log_file("static/full_player", sprintf("%s(%s) full %s(%s) on %s\n",
	    this_player()->query("name"),this_player()->query("id"),
	    me->query("name"),me->query("id"),ctime(time()) ));
  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

	if( wiz_level(this_player())<6 ) return 1;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[cloak]: wave <多少錢> <錢幣種類>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你搖了半天卻什麼也沒有出來。\n");
        if( amount < 1 )
                return notify_fail("你搖了半天卻什麼也沒有出來。\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$N使勁的掏口袋﹐突然從袋子裡掏出%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[cloak]: 你想讓誰 PK 誰啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 這個生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 這個生物.\n");

	message_vision("$N用超級麵包師父的頂級功\力, 讓"+
		ob1->name()+"跟"+ob2->name()+"開始互相甌鬥。",
		this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;

  me = this_player();
  wiz = wizhood (me);
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
    return 0;
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 2)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("本披風不能給手下以外的人。\n");
    return 1;
  }

  ob = present ("wiz cloak", me);
  if (!ob) write ("你沒有這樣東西。\n");
  who = find_player(whos);
  if (!who) write ("沒有這個人。\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N給$n一件披風。\n", me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("[cloak]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, 沒有"+str+"\n");
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int query_autoload()
{
  if(!this_player()) return 0;

  if (wizardp(this_player()))
    return 1;
  else return 0;
}

int force_quit (string str)
{
  object ob, usr;

  seteuid(getuid());
  if (!str) return notify_fail ("[cloak]: Hey you! 你想讓誰 quit 啊\n");

  
  if (!(ob=find_player(str)))
    return notify_fail ("[cloak]: 沒這個人("+str+")\n");

  if (objectp (ob))
    destruct( ob );
  else
    write ("[test] cloak: cannot force quit\n");
  return 1;
}
