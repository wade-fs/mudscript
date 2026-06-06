inherit NPC;

void create()
{
      set_name("蟹角長毛牛",({"crab-ox"}));
        set("long","西宮龍王的座騎,因為擅離職守,所以被龍王貶到人間!!\n"    );
        set("race", "野獸");
        set("age", 110);
       set("attitude","peacful");    
        set("max_sen",7000);
        set("max_gin",7000);
        set("max_kee",4000);
        set("max_force", 10000);
        set("force",10000);
        set("force_factor",5);
        set("str", 110);
        set("cor", 40);
        set("spi", 40);
        set("int", 60);
        set("limbs", ({ "頭部", "身體", "前腳", "後腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 70);
        set_skill("dodge",50);
        set_temp("apply/damage", 160);
        set_temp("apply/armor", 50);
        set("combat_exp",100000);      
        setup();
}            
