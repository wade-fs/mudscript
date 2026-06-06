inherit NPC;
void create()
{
  set_name("灰狼",({"gray wolf","gray","wolf"}));
  set("race", "野獸");
  set("age",4);
  set("long","一隻灰狼,正靜靜地看著你.\n");
  set("str", 30);
  set("con", 30);
  set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("combat_exp",150000);
  set("max_kee",1000);
  set("kee",1000);
  set("max_force",500);
  set("force",500);
  set("force_factor",10);
  set_temp("apply/armor", 30);
  set_temp("apply/attack", 10);
  set_skill("dodge",120);
    set_skill("parry",100);
        setup();

}
