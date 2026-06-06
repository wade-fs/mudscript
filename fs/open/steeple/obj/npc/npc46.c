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
        set("title",HIW + "～幻影～" + HIC + "武學之盡" + NOR);
        set("force",2000000);
        set("max_gin",15000);
        set("max_sen",15000);
        set("max_kee",100000);
        set("bellicosity",5000);
        set("max_force",600000);
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
message_vision(HIY + "獨孤莫琉運起『核爆掌』向你一擊，頓時掌氣已印在你的胸膛！\n" + NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-3000); }
   }
   else
   {
message_vision(HIC + "獨孤莫琉心感疲狽，運起『獨孤秘傳法咒』一道藍光從蒼天發出，頓時精神百倍。\n" + NOR,me);
    me->delete_busy();
    me->clear_condition();
if(random(9) >= 5) {
    me->receive_curing("kee",4000);
    me->receive_heal("kee",4000); }
   }
  }
}
  ::heart_beat();
  }

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW + "系統：戰鬥停止，$N回收中，。\n" + NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 47)
       {
        tell_object(users(),HIY + "
恭喜"HIW+me->query("name")+HIY"挑戰" + HIG + "『" + HIR + "第四十六層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第四十七層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",47);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
