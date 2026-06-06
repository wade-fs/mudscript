inherit NPC;

void create() 
{
        set_name("飛刺鳥",({"fly-bird","bird"}));
        set("long","
它是穿梭於幻結界的生物之一，一聞到生人氣息就蹦出來吃人。
但是如今她身處於琰揚湖內，受到水邪將--水柔纏的感化，暴戾
之氣以消失殆盡。\n");
        set("age",1937);
        set("str",30);
        set("cor",30);
        set("race","野獸");
        set("gender","雄性");
        set("max_gin",6000);
        set("max_kee",6000);
        set("max_sen",6000);
        set("max_force",20000);
        set("force",20000);
        set("force_factor",20);
        set("combat_exp",800000);
        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("parry",300);
        set_skill("force",250);
        set("limbs",({"頭部","尾部","翅膀","爪子"}));
        set("verbs",({"dunt","claw","poke"}));
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
}

void die()
{
object ob,me,obj;
        ob=this_object();
        me=ob->query_temp("last_damage_from");
        me->add_temp("evil/water/killed",1);
::die();
}
