inherit NPC;

void create()
{
      set_name("雞身蛇尾鳥",({"evil-bird","bird"}));
        set("long","上古時代的神獸,擁有雞的身體與蛇的尾巴,但是在邪惡的洞穴中
        待太久了,所以變成了邪獸!!\n"    );
        set("race", "野獸");
        set("age", 360);
       set("attitude","aggressive");    
        set("max_kee",6000);
        set("max_sen",7000);
        set("max_gin",7000);
        set("max_force",6000);
        set("force",6000);
        set("force_factor",5);
        set("str", 110);
        set("cor", 40);
        set("spi", 40);
        set("int", 60);
        set("limbs", ({ "頭部", "身體", "前腳", "後腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 70);
        set_skill("dodge",120);
        set_temp("apply/damage", 160);
        set_temp("apply/armor", 50);
        set("combat_exp",500000);      
        setup();
        add_money("gold",5);
}            
