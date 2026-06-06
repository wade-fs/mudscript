#include <ansi.h>
inherit NPC;
void create()
{
        set_name("獨孤莫琉",({"degu liu","liu"}));
        set("long","此人跟獨孤莫愁為兄弟，和師父獨孤嵊一樣想平魔刀。\n");
        set("gender","男性");
        set("combat_exp",7000000);
        set("attitude","aggressive");
        set("age",50);
        set("class","fighter");
        set("family/family_name","雪蒼派");
        set("quests/read_snow",1);
        set("title",HIC"武學之盡"NOR);
        set("force",20000);
        set("max_gin",15000);
        set("max_sen",15000);
        set("max_kee",25000);
        set("bellicosity",5000);
        set("max_force",20000);
        set("force_factor",50);
        set("mpower",1);
        set("str",45);
        set("cor",45);
        set_skill("snow-martial", 100);
        set_skill("snowforce", 100);
        set_skill("snow-kee",100);
        set_skill("black-steps",100);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("force",100);
        map_skill("unarmed", "snow-martial");
        map_skill("parry","snow-kee");
        map_skill("force", "snowforce");
        map_skill("dodge", "black-steps");
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
        carry_object("/open/snow/obj/figring")->wield();
        add_money("gold", 20);
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
room=environment(me);
target=me->query_enemy(room);
if(i=sizeof(target)) {
if(random(100) > 50)
{
if(random(9) >= 5)
{
message_vision(HIY"獨孤莫琉運起『核爆掌』向你一擊，頓時掌氣已印在你的胸膛！\n"NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-700); }
   }
   else
   {
message_vision(HIC"獨孤莫琉心感疲狽，運起『獨孤秘傳法咒』一道藍光從蒼天發出，頓時精神百倍。\n"NOR,me);
    me->delete_busy();
    me->clear_condition();
if(random(9) >= 5) {
    me->receive_curing("kee",2000);
    me->receive_heal("kee",1000); }
   }
  }
}
  ::heart_beat();
  }
void greeting(object ob)
{
if(ob->query("family/family_name")=="魔刀門"||ob->query("family/family_name")=="魔刀莫測")
  {
   command("say 哼！哼！血洗魔刀，受死吧！\n ");
   kill_ob(ob);
   command("exert roar");
}}
void die()
{
   object me;
   me=this_object()->query_temp("last_damage_from");
   if (me && userp(me))  {
   me->add("snow-head",50);
tell_room(environment(),sprintf("%s從獨孤莫琉身上切下一顆人頭。\n",me->name()));
   }
   ::die();
}
