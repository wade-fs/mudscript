// wu 改版 by ACKY
//增加判斷玩家天賦異常的紀錄 by blazakira 2011/7/21
//增加新活動 戰功忍者的動作輔助判斷 by blazakira 2011/8/25
//恢復玩家title的錯誤 by blazakira 2011/10/17

#include <ansi.h>
inherit NPC;

void do_start_move();

void create()
{
  set("long","
    莫無愁, 天下第一黑道盟主, 擅長暗殺, 靠獎金為生,
接收各幫派委任, 若有被幫派追緝的人出現在他的面前, 絕
對是殺無赦, 其武功\為極火功\及極火掌, 來歷不祥!
");
  set("gender","男性");
  set("class","fighter");
  set("nickname",HIR + "極道殺手" + NOR);
  set("title","黑道盟主");
  set_name("莫無愁",({"wu"}));
  set("combat_exp",100000000);
  set("attitude","hero");
  set("score",5000000);
  set("bellicosity",10000);
  set("age",45);
  set("max_force",1000000);
  set("force",1000000);
  set("max_kee",100000);
//  set("kee",100000);
  set("max_gin",50000);
  set("max_sen",50000);
  set("str", 35);
  set("cor", 35);
  set("no_lyssa",1);
  set("cps", 30);
  set("per", 30);
  set("int", 30);
  set("force_factor",100);
  set_skill("dodge",500);
  set_skill("force",500);
  set_skill("move",500);
  set_skill("parry",500);
  set_skill("mogi-steps",500);
  set_skill("firestrike",500);
  set_skill("unarmed",500);
  set_skill("literate",500);
  set_skill("fireforce",500);
  set_temp("armor_vs_force",5000);
  map_skill("force","fireforce");
  map_skill("unarmed","firestrike");
  map_skill("dodge","mogi-steps");
  map_skill("move","mogi-steps");
  map_skill("parry","firestrike");
  set("functions/gold-fire/level",100);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  setup();
  carry_object("/autoload/mogi/fire-armor")->wear();
  carry_object("/autoload/mogi/fire-cloud-boots")->wear();
  carry_object("/autoload/mogi/fire-belt")->wear();
  carry_object("/autoload/mogi/daemon-cloak")->wear();
  carry_object("/autoload/mogi/fire-dragon")->wield();
  add_money("gold",1000);
}

void init()
{
  object ob = this_player(),room=environment();
  if( ob->query("ckill") ) {
    add_action( "do_ban" , "", 1 );
//void greeting(object ob)
//{
    ob->start_busy(5);
    command( "say 哈! 哈! 又一個來送死的! 看掌!");
    command( "perform fireforce.gold-fire" );
    kill_ob(ob);
  }
/*
  if( ob->query("mk-blade")&&!ob->query("get-new-title") ) {
    if( ob->query("gender")=="男性" ) {
      if( ob->query("title")!="漩羽刀皇" && !ob->query_temp("powerup") &&
          !ob->query_temp("addbasic")) {
        tell_object( ob, HIW + "你使用邪靈制刀術錯亂, 我幫你還原title...\n" + NOR );
        ob->set( "title", "漩羽刀皇");
      }
    }
    else
      if(ob->query("title")!="刀魂幽姬" && !ob->query_temp("powerup") &&
          !ob->query_temp("addbasic")) {
        tell_object(ob,HIW + "你使用邪靈制刀術錯亂, 我幫你還原title...\n" + NOR );
        ob->set( "title", "刀魂幽姬");
      }
  }
*/

  if(room && room->query("assassinating"))
    do_start_move();

  if(interactive(this_player()) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting", 0, this_player());
  }
}

int do_ban()
{
  object ob = this_player();
  if( ((string)query_verb() == "exert" ) ||
      ((string)query_verb() == "perform" ) ||
      ((string)query_verb() == "do" ) )
    return 1;
  return 0;
}

void greeting(object me)
{
  if(!me) return;
  if(me->query("per")==35) {
    me->set("origional_per",10);
    write_file("/u/b/blazakira/fix/autoload/gift_per",sprintf("%s(%s)的天賦per為35，重新設定per為10，於%s。\n",me->name(1),me->query("id"),ctime(time())));
  }
  if(me->query("title")==HIR + "δ"HIW+BRED"血靈" + NOR + "" + HIR + "δ" + HBBLU + "" + BLK + "闇月" + HIC + "劍魔" + NOR) {
    me->set("title",HIR + "δ"HIW+BRED"血靈" + NOR + ""HIR + "δ"BLK+HBBLU"闇月"HIC+HBBLU"劍魔" + NOR);
  }
  if(me->query("title")==HIW + "Π" + HIR + "魔" + HIC + "亟" + HIY + "劍宗" + HIW + "Π") {
    me->set("title",HIW + "Π" + HIR + "魔" + HIC + "亟" + HIY + "劍宗" + HIW + "Π" + NOR);
  }
}

void do_start_move()
{
  object ob,npc,ppl;
  npc=find_living("assassination ninja");

//狀態提示用 不然都不知道是否npc停止了
  ppl=find_player("blazakira");
  if(ppl) {
    if(!ppl->query("env/wn_msg_off")) {
      if(!npc)
        tell_object(ppl,HIR+BBLU+"抓不到npc。\n"+NOR);
      else {
        tell_object(ppl,HIR+BBLU+"暗殺輔助中。\n"+NOR);
        if( environment(npc) )
          tell_object(ppl,HIY+BBLU"目前npc位於"+environment(npc)->short()+"  -- "+file_name(environment(npc))+"\n" + NOR);
      }
    }
  }
  if(npc && !query("call_npc")) //如果暗殺任務開始 就送npc過去維持ninja心跳
  {
    if(!npc || !environment(npc)) return;
    set("call_npc",1);
    ob=new("/open/japan/npc/war_ninja3.c");
    ob->move(environment(npc));
    destruct(ob);
    delete("call_npc");
  }
}
