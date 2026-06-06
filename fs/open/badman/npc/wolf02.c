inherit NPC;

void create()
{
     set_name("紅狼", ({ "red wolf","red","wolf" }));
        set("race", "野獸");
    set("age",7);
    set("long","一隻灰狼,正靜靜地看著你.\n");
        set("str", 30);
         set("cor", 30);
        set("con", 30);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
    set("combat_exp",320000);
    set("max_kee",1500);
    set("kee",1500);
    set("max_force",750);
    set("force",750);
    set("force_factor",15);
  set_temp("apply/armor",100);
  set_temp("apply/attack", 100);
    set("attitude","peaceful");
        set("random_move",2);
        set("chat_chance",10);
        set("chat_msg", ({
            (: "random_move" :),
                       }) );
  set_skill("dodge",200);
  set_skill("parry",150);
        setup();

}
