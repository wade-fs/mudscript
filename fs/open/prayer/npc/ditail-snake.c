inherit NPC;

void create()
{
      set_name("人身雙尾蛇",({"ditail-snake"}));
        set("long","伏羲式飼養的寵物之一,性極暴燥,其兩條尾巴各具有不同的能力!!\n"    );
        set("race", "野獸");
        set("age", 110);
       set("attitude","aggressive");    
        set("max_kee",2500);
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
        set("combat_exp",50000);      
        setup();
}            
