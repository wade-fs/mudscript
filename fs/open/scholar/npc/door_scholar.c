//瀧山弟子
inherit NPC;
void create()
{
        set_name("儒門護衛",({"door scholar","scholar"}));
        set("gender","男性");
        set("age",25);
        set("family/family_name","儒門");
        set("class","scholar");
        set("force",1500);
        set("max_force",1500);
        set("force_factor",10);
        set("str",25);
        set("long","儒門中的高階儒生之一，被託負重任守衛大門。\n");
        set("combat_exp",200000);
        set_skill("stabber",70);
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill("force",60);
        set_skill("poetforce",60);
        set_skill("knowpen",80);
        set_skill("winter-steps",40);
        map_skill("dodge","winter-steps");
        map_skill("parry","knowpen");
        map_skill("stabber","knowpen");
        map_skill("force","poetforce");
        setup();
        carry_object("/open/scholar/obj/pen2")->wield();
        add_money("gold",15);
}
int accept_fight(object who)
{
return notify_fail("儒門護衛說道 : 現在正在值勤中 , 請不要打擾好不好。\n");
}

