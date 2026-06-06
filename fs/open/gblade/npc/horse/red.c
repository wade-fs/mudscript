#include <ansi.h>
#include <mudlib.h>
inherit NPC;
void create() {
set_name(HIR + "赤兔駒" + NOR, ({"red horse" , "horse"}));
set("title", "西域良駒");
set("long", "
相傳牠原為魏晉南北朝時，呂布的座騎，也曾為三國時關雲長的座騎，但
為何又重現江湖，卻沒有人知道，能駕馭赤兔者，必為英雄豪傑也。\n");
set("str",45);
set("cor",45);
set("cps",45);
set("max_force",3000);
set("force",3000);
set("horse",1);
set("max_gin",10000);
set("max_kee",10000);
set("max_sen",10000);
        set("age", 30);
        set("race", "野獸");
        set("gender", "雄性");
        set("combat_exp", 1000000);
        set("attitude", "peaceful");
        set("score",10000000);
        set("gold", 80);
        set("exp", 550000);
        set_skill("parry", 130);
        set_skill("move", 130);
        set_skill("dodge", 130);
        set_skill("unarmed", 130);
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
}

int do_ride(string str) {
        object me,horse;
        me = this_player();
        horse = this_object();
        if((str != "horse") && (str != horse->query("id")))
           return notify_fail("你想騎什麼？\n");
        if(me->query_skill("riding", 1) < 80)
           return notify_fail("你的騎術不夠，無法駕馭牠。\n");
       if(horse->query("horse")!=1)
       return notify_fail("這不是馬不能騎唷！\n");
   if(me->query_temp("marks/ascend"))
return notify_fail("有騎馬了還想騎，想被 K 呀。\n");

       if(me->query("class")!="blademan")
        return notify_fail("你不是刀客，所以不能騎馬。\n");
        if(me->query("id") != horse->query_temp("my_boss")) {
message_vision("$N被"+horse->query("name")+"狠狠的踢了一腳，似乎受了點傷！\n",me);
           me->add("kee", -50);
           return 1;
        }
        if(me->query_temp("is_riding"))
           return notify_fail("你已經騎在馬上了。\n");
message_vision("$N一個翻身，已騎在"+horse->query("name")+"的背上！\n",me);
        me->set_temp("is_riding", 1);
if(me->query("family/family_name")=="魔刀門" ||
   me->query("family/family_name")=="魔刀莫測") {
        me->add_temp("apply/attack", 40);
        me->add_temp("apply/parry",40);
        me->add_temp("apply/defense",40);
        me->add_temp("apply/damage",40);
        me->add_temp("apply/armor", 40);
        me->add_temp("apply/dodge", 40);
        me->add_temp("apply/move", 80); } else {
        me->add_temp("apply/attack", 40);
        me->add_temp("apply/parry",40);
        me->add_temp("apply/defense",40);
        me->add_temp("apply/damage",40);
        me->add_temp("apply/armor", 40); }
	me->set_temp("ride_name",me->name()+"騎在一匹"+horse->name()+"上");
return notify_fail("頓時，"+horse->query("name")+"仰天長鳴一聲！人馬合一，你的力量增加了不少！\n");
}

int do_dismount() {
        object me,horse;
        me = this_player();
        horse = this_object();
        if(!me->query_temp("is_riding"))
        return notify_fail("你現在並沒有騎馬！\n");
        if(me->query("id") != horse->query_temp("my_boss"))
        return notify_fail("這匹馬不是你的座騎！\n");
        me->delete_temp("is_riding");
if(me->query("family/family_name")=="魔刀門" ||
   me->query("family/family_name")=="魔刀莫測") {
        me->add_temp("apply/attack", -40);
        me->add_temp("apply/parry",-40);
        me->add_temp("apply/defense",-40);
        me->add_temp("apply/damage",-40);
        me->add_temp("apply/armor", -40);
        me->add_temp("apply/dodge", -40);
        me->add_temp("apply/move", -80); } else {
        me->add_temp("apply/attack", -40);
        me->add_temp("apply/defense",-40);
        me->add_temp("apply/parry",-40);
        me->add_temp("apply/damage",-40);
        me->add_temp("apply/armor", -40); }
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
        me->add("force", me->query("max_force")/10);
        return notify_fail("你的內力增加了！\n");
}

void die() {
        object me;
        me = find_living((string)this_object()->query_temp("my_boss"));
        if(me->query_temp("is_riding")) {
if(me->query("family/family_name")=="魔刀門" ||
   me->query("family/family_name")=="魔刀莫測") {
           me->add_temp("apply/defense",-40);
           me->add_temp("apply/attack", -40);
           me->add_temp("apply/parry",-40);
           me->add_temp("apply/armor", -40);
           me->add_temp("apply/damage",-40);
           me->add_temp("apply/dodge", -40);
           me->add_temp("apply/move", -80);
        } else {
        me->add_temp("apply/attack", -40);
        me->add_temp("apply/parry",-40);
        me->add_temp("apply/defense",-40);
        me->add_temp("apply/damage",-40);
        me->add_temp("apply/armor", -40); } }
        me->delete_temp("ride_name");
        me->delete_temp("horse");
        me->delete_temp("is_riding");
        me->delete_temp("have_horse");
	destruct(this_object());
}

int accept_fight(object me) {
	return notify_fail("這是別人的財產，你殺不得！\n");
}

int accept_kill(object me) {
	return notify_fail("這是別人的財產，你殺不得！\n");
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
if( random(100) > 85)
 {
    enemy=mob->query_enemy();
    if(i=sizeof(enemy)) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
message_vision(HIY + "
突然間，赤兔駒像發狂似的向$N衝撞而來\n"+
"$N閃避不及，被撞個四腳朝天，鮮血直吐\n" + NOR,target);
target->receive_damage("kee",275);
      target->start_busy(1);
      COMBAT_D->report_status(target,1);
    }
 }
}
   ::heart_beat();
}
