#include <ansi.h>
#include <mudlib.h>
inherit NPC;
inherit SSERVER;
void create() {
set_name(HIR + "汗血寶馬" + NOR,({"blood horse" , "horse"}));  
set("title", HIW + "〒" + HIY + "神駒" + HIW + "〒" + NOR);
set("long", "每隔千年才出現一次的傳說之神駒。\n");
set("str",50);
set("cor",50);
set("cps",50);
set("horse",1);
set("force",10000);
set("max_force",10000);
set("max_gin",20000);
set("max_kee",20000);
set("max_sen",20000);   
set("age", 30);
set("race","野獸");
set("gender", "雄性");
set("combat_exp", 2000000);
set("attitude", "peaceful");
set("score",10000000);
set("gold", 100);
set("exp", 900000);
        set_skill("parry", 150);
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set("limbs",({"馬頭","馬腳","馬腿","馬背","馬腹"}));
        set("verbs",({"bite","claw"}));
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        setup();
}

void init() {
        add_action("do_ride","ride");
        add_action("do_dismount","dismount");
        add_action("do_full","addforce");
        add_action("do_freehorse","free_horse");
}

int do_ride(string str) {
        object me,horse;
        me = this_player();
        horse = this_object();

        if((str != "horse") && (str != horse->query("id")))
           return notify_fail("你想騎什麼？\n");

        if(horse->query("horse")!=1)
           return notify_fail("這不是馬不能騎唷！\n"); 

        if(me->query_temp("marks/ascend"))
           return notify_fail("有騎馬了還想騎，想被 K 呀。\n");

        if(me->query("id")!="vigel")
           return notify_fail("這不是你的座騎，不要隨便亂騎喔!!\n");

        if(me->query_temp("is_riding"))
           return notify_fail("你已經騎在馬上了。\n");
message_vision("$N以俊逸的姿勢躍向空中轉體三週半，啪一聲！已騎在"+horse->query("name")+"的背上！\n",me);
        me->set_temp("is_riding", 1);
        me->add_temp("apply/attack",60);
        me->add_temp("apply/parry",60);
        me->add_temp("apply/defense",60);
        me->add_temp("apply/damage",60);
        me->add_temp("apply/armor",60);
        me->add_temp("apply/dodge",60);
        me->add_temp("apply/move",110);
	me->set_temp("ride_name",me->name()+"正騎著"+horse->name());
return notify_fail("騎上"+horse->query("name")+"之後，"+me->name()+"神威凜凜，有如天神降世。\n");
}

int do_dismount() {
        object me,horse;
        me = this_player();
        horse = this_object();

        if(!me->query_temp("is_riding"))
           return notify_fail("你現在並沒有騎馬！\n");

        if(me->query("id") != "vigel")
           return notify_fail("這匹馬不是你的座騎！\n");

        me->delete_temp("is_riding");
        me->add_temp("apply/attack",-60);
        me->add_temp("apply/parry",-60);
        me->add_temp("apply/damage",-60);
        me->add_temp("apply/armor",-60);
        me->add_temp("apply/defense",-60);
        me->add_temp("apply/dodge",-60);
        me->add_temp("apply/move",-110);
	me->delete_temp("ride_name");
        message_vision(HIW + "$N一個翻身下了馬來！\n" + NOR,me);
        return 1;
}

int do_full() {
        object me;
        me = this_player();

	if(!me->query_temp("is_riding"))
	return notify_fail("你沒有騎馬唷。\n");

        if(me->query("max_force") == 0)
           return notify_fail("你並沒有內力！\n");

        if(me->query("force") >= me->query("max_force"))
           return notify_fail("你的內力已滿！\n");

        me->add("force", me->query("max_force")/4);
        return notify_fail("你的內力增加了！\n");
}

int do_freehorse()
{
        object me;
        me = find_living((string)this_object()->query_temp("my_boss"));
        message_vision(HIG + "$N在$n" + HIG + "背上一拍，摸摸$n" + HIG + "的頭，$n" + HIG + "高興地朝著廣大的草原飛奔而去。\n" + NOR,me,this_object());
        if(me->query_temp("is_riding"))
         {
           me->add_temp("apply/attack",-60);
           me->add_temp("apply/parry",-60);
           me->add_temp("apply/damage",-60);
           me->add_temp("apply/defense",-60);
           me->add_temp("apply/armor",-60);
           me->add_temp("apply/dodge",-60);
           me->add_temp("apply/move",-100);
         }
        me->delete_temp("ride_name");
        me->delete_temp("horse");
        me->delete_temp("is_riding");
        me->delete_temp("have_horse");
	destruct(this_object());
	return 1;
}

void die()
{
        object me;
        me = find_living((string)this_object()->query_temp("my_boss"));
        if(me->query_temp("is_riding"))
         {
           me->add_temp("apply/attack",-60);
           me->add_temp("apply/parry",-60);
           me->add_temp("apply/damage",-60);
           me->add_temp("apply/defense",-60);
           me->add_temp("apply/armor",-60);
           me->add_temp("apply/dodge",-60);
           me->add_temp("apply/move",-100);
         }
        me->delete_temp("ride_name");
        me->delete_temp("horse");
        me->delete_temp("is_riding");
        me->delete_temp("have_horse");
	destruct(this_object());
}

int accept_fight(object me) {
	return notify_fail("這是別人的財產, 你殺不得!\n");
}

int accept_kill(object me) {
	return notify_fail("這是別人的財產, 你殺不得!\n");
}
void heart_beat()
{
 object env,mob,*enemy,target,me;
 int i,gin,kee,sen;
 mob = this_object();
 env = environment(mob);
 me = this_player();
 gin = me->query("gin");
 kee = me->query("kee");
 sen = me->query("sen");
if(me->query("id")!= "vigel")
{
set_heart_beat(0);
}
else
{
if( random(100) > 85)
 {
    enemy=mob->query_enemy();
    if(i=sizeof(enemy))
    {
    target=offensive_target(mob);
    if(!target) return;
    if( env == environment(target) )
    {
message_vision(HIR + "
汗血寶馬突然人立起來，發出震撼人心的狂野嘶吼，$N心神受到強烈音波衝擊，
耳裡頓時嗡嗡作響，丹田氣血翻湧，無法自制。\n" + NOR,target);
      target->start_busy(1);
      COMBAT_D->report_status(target,1);
    }
    }
 }
 if(env == environment(me) && me->is_fighting() && !me->query_temp("pk_fight"))
 {
  if(kee < 0.1*(me->query("max_kee")) || sen < 0.1*(me->query("max_sen")) || gin < 0.1*(me->query("max_gin")))
  {
   if(random(3) == 1)
   {
      message_vision(HIR + "就在$N性命危急的時候，$n奮不顧身的將$N揹起，馬蹄一振，像道紅光般消失在眾人面前。\n" + NOR,me,mob);
      me-> move ("/open/common/room/inn");
      mob-> move ("/open/common/room/inn");
   }
  }
 }
   ::heart_beat();
}
}
