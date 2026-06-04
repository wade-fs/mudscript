//因為取消fanset特殊地點功能，因此相對應將馬的戰鬥能力調整回來，並修正心跳問題 by frequency
#include <ansi.h>
#include <mudlib.h>
inherit NPC;
inherit SSERVER;
void create() {
set_name(HIW + "佩加薩斯" + NOR,({"sky horse" , "horse"}));  
set("title", HIC + "天馬" + NOR);
set("long", "能在天空自由飛翔的傳說神駒。\n");
set("class","blademan");
set("str",50);
set("cor",50);
set("cps",50);
set("horse",1);
set("force",40000);
set("force_factor",40);
set("max_force",20000);
set("max_gin",20000);
set("max_kee",20000);
set("max_sen",20000);
set("bellicosity",4000); 
set("age", 30);
set("race","野獸");
set("gender", "雄性");
set("combat_exp", 2000000);
set("attitude", "peaceful");
set("score",10000000);
set("gold", 100);
set("exp", 1000000);
        set_skill("parry", 120);
        set_skill("move", 120);
        set_skill("dodge", 120);
        set_skill("move", 120);
        set_skill("unarmed", 120);
        set_skill("force", 300);
        set_skill("beast", 120);
        set_skill("sixforce", 120);
        set_skill("fly-steps", 120);
        map_skill("parry","beast");
        map_skill("dodge","fly-steps");
        map_skill("move","fly-steps");
        map_skill("unarmed","beast");
        map_skill("force","sixforce");
        set("limbs",({"馬頭","馬腳","馬腿","馬背","馬腹"}));
        set("verbs",({"bite","claw"}));
        set_temp("apply/armor",80);
        set_temp("apply/defense",80);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        setup();
}

void init() {
        add_action("do_ride","ride");
        add_action("do_dismount","dismount");
        add_action("do_full","addforce");
        add_action("do_freehorse", "free_horse");
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

        if(me->query("id")!="alucard" && me->query("id") != "frequency")
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
        me->add_temp("apply/move",60);
	me->set_temp("ride_name",me->name()+"正騎著"+horse->name());
	set_heart_beat(1);
return notify_fail("騎上"+horse->query("name")+"之後，"+me->name()+"神威凜凜，有如天神降世。\n");
}

int do_dismount() {
        object me,horse;
        me = this_player();
        horse = this_object();

        if(!me->query_temp("is_riding"))
           return notify_fail("你現在並沒有騎馬！\n");

        if(me->query("id") != "alucard")
           return notify_fail("這匹馬不是你的座騎！\n");

        me->delete_temp("is_riding");
        me->add_temp("apply/attack",-60);
        me->add_temp("apply/parry",-60);
        me->add_temp("apply/damage",-60);
        me->add_temp("apply/armor",-60);
        me->add_temp("apply/defense",-60);
        me->add_temp("apply/dodge",-60);
        me->add_temp("apply/move",-60);
	me->delete_temp("ride_name");
        message_vision(HIW + "$N一個翻身下了馬來！\n" + NOR,me);
        set_heart_beat(1);
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
        if(me->query("id") != "alucard" && me->query("id") != "frequency")  return 0;
        message_vision(HIB + "$N在$n" + HIB + "背上一拍，摸摸$n" + HIB + "的頭，$n" + HIB + "高興地朝著廣大的天空疾飛而去。\n" + NOR,me,this_object());
        if(me->query_temp("is_riding"))
         {
           me->add_temp("apply/attack",-60);
           me->add_temp("apply/parry",-60);
           me->add_temp("apply/damage",-60);
           me->add_temp("apply/defense",-60);
           me->add_temp("apply/armor",-60);
           me->add_temp("apply/dodge",-60);
           me->add_temp("apply/move",-60);
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
           me->add_temp("apply/move",-60);
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
 object env,me,*target;
 int i,j;
 me = this_object();
 env = environment(me);
if(me->query("kee") < 5000 && random(3) == 2)
 {
 message_vision("$N" + HIY + "眼見小命不保，連嚼了幾口" + HIG + "世界樹之葉" + HIY + "，傷勢頓時痊癒許\多。\n" + NOR,me);
 me->receive_heal("kee",3000);
 me->receive_curing("kee",3000+random(2000));
 }
if( random(100) > 85)
 {
    target = me->query_enemy(env);
    i=sizeof(target);
    if(target && me->is_fighting())
    {
message_vision(HIC + "\n佩加薩斯突然人立起來，發出震撼人心的狂野嘶吼，令人心神受到強烈音波衝擊，
耳裡頓時嗡嗡作響，丹田氣血翻湧，無法自制。\n" + NOR,me);    
    for(j=0;j<i;j++)
    {
      target[j]->start_busy(random(2)+1);
      COMBAT_D->report_status(target[j],1);
    }
    }
 }
 ::heart_beat();
}
