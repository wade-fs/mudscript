//御前護衛 made by rora
//增加撿拾道具的功能 為了稍微減輕系統負擔 by blazakira 2010/10/20

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("御前護衛",({"king guard","guard"}));
        set("gender","男性");
        set("age",30);
        set("attitude", "heroism");
        set("str",45);
        set("cor",45);
        set("cps",45);
        set("con",45);

        set("long","保護天子的勇猛戰士，盡忠職守，不茍言笑。\n");
        set("combat_exp",4500000);
        set("force",50000);
        set("max_force",750000);
        set("max_kee",400000);
        set("kee",400000);
        set("force_factor",80);

        set_skill("blade",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("dodge",200);
        set_skill("godblade",200);
        set_skill("bss-steps",200);
        set_skill("fireforce",200);
        set_skill("bss-parry",200);
        map_skill("blade","godblade");
        map_skill("parry","bss-parry");
        map_skill("dodge","bss-steps");
        map_skill("force","fireforce");

        setup();

        carry_object("/open/gblade/obj/blade2")->wield();
        carry_object("/open/gblade/obj/gold-robe")->wear();
        carry_object("/open/gblade/obj/gold-armor")->wear();
        carry_object("/open/gblade/obj/gold-boots")->wear();
        add_money("gold",5);
}

void init()
{
        add_action("do_fight", "fight");
        add_action("do_fight", "kill");
  call_out("greeting", 1, this_player());
//  set_heart_beat(1);
}

void greeting()
{
//基本上是針對純喫茶 小拉大龍棕 喚雲扇等 生活物資
  object *inv,ob;
  int i;
  ob=this_object();
  inv=all_inventory(environment(ob));
  for(i=0;i<sizeof(inv);i++){
    if(!inv[i]) continue;
    if(!inv[i]->query("食物") && !inv[i]->query("液體") && inv[i]->query("id") != "cloud fan") continue; //需注意該房間是否固定場景的物件
    message_vision(HIC"$N以很遺憾的心情將"+inv[i]->query("name")+HIC"("+inv[i]->query("id")+HIC")歸入塵土風逝。\n"NOR,ob);
    destruct(inv[i]);
  }
}

int do_fight(string arg)
{
        object who;
        who = this_player();

        if( !arg || (arg!="guard" && arg!="king") )
                return notify_fail("你想攻擊誰﹖\n");
        else {
                kill_ob(who);
        }

        return 1;
}
int accept_kill(object ob)
{
        command("wield all");
        command("wear all");
        return 1;
}
/*
void heart_beat()
{
  object mob=this_object();
//每次心跳就撿拾一次並刪除因玩家離線所掉落的道具 by blazakira
  if(!environment()) return ;
  if(!mob) return ;
  if( mob->query("kee") <= 0 )
  {
    set_heart_beat(0);
    mob->die();
  }
  else {
    if (present("tea",environment(mob))){
      message_vision(HIC"$N以很遺憾的心情將純喫茶(Tea)歸入塵土風逝。\n"NOR,mob);
      destruct(present("tea",environment(mob)));} //刪除純喫茶
    if (present("cloud fan",environment(mob))){
      message_vision(HIC"$N以很遺憾的心情將喚雲扇(Cloud fan)歸入塵土風逝。\n"NOR,mob);
      destruct(present("cloud fan",environment(mob)));} //刪除喚雲扇
    if (present("pyramid mass",environment(mob))){
      message_vision(HIC"$N以很遺憾的心情將小拉大龍棕(Pyramid mass)歸入塵土風逝。\n"NOR,mob);
      destruct(present("pyramid mass",environment(mob)));} //刪除小拉大龍棕
  }

  set_heart_beat(1);
  ::heart_beat();
}
*/