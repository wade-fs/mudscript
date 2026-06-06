#include <ansi.h>
#include <combat.h>
#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("魔刀莫測",({"oldman"}));
set("long", "一個看起來全身髒盻盻的老人，腳上還有一個腳銬，看起來像是被關在這裡的。\n");
        set("gender", "男性" );
        create_family("魔刀莫測",1,"開創始祖");
        set("family/family_name","魔刀莫測");
        set("have_book",1);
        set("title",HIW + "～幻影～" + NOR + "魔仙雪～刀劍蒼");
        set("age",70);
        set("env/魔性六斬","YES");
set("mpower",1);
        set("str",45);
        set("class","blademan");
        set("guild_class","blademan");
        set("cor", 30);
        set("cps", 30);
        set("int", 25);
        set("max_gin",1000);
        set("max_sen",1000);
        set("max_force",80000);
        set("force",80000);
        set("force_factor",30);
        set("kee",10000);
        set("score",100000);
        set("max_kee",10000);
        set("bellicosity",3000);
        set_skill("cure",60);
        set_skill("riding",100);
        set_skill("force", 100);
        set_skill("blade",120);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("powerforce", 100);
        set_skill("dragon-blade", 120);
        set_skill("parry", 100);
        map_skill("parry","dragon-blade");
        map_skill("blade","dragon-blade");
        map_skill("force","powerforce");
        set("combat_exp",1500000);
        set("chat_chance_combat",100);
        set_temp("apply/armor",90);
        set("chat_msg_combat",({
        (: perform_action, "blade.power-dest" :),
      }));
        add_temp("apply/dodge",30);
        setup();
        carry_object("/daemon/class/blademan/obj/iceblade")->wield();
}
void heart_beat()
{
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        :: heart_beat();
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
if(me->query("quest/start_game")< 21)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第二十層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第二十一層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",21);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}


