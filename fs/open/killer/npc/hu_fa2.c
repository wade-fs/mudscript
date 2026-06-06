// 這是小渡的標準NPC
inherit NPC;
void create()
{
  object ob1;

  set_name("韋奕玄",({"we_eny shan","shan"}));
  set("title","銀狼組組長");
  set("long","此人乃負責分化各派，計畫一切行動。一身功\夫亦高的驚人。");
  set("gender","男性");
  set("combat_exp",500000); 
  set("attitude","friendly");
  set("force_factor",10);
  set("age",40);
  set("class","killer");

  set("str", 30);
  set("int", 68);
  set("spi", 50);
  set("cps", 45);
  set("con", 25);
  set("kar", 50);

  set("max_gin",200);
  set("eff_gin",200);
  set("gin",200);
  set("max_kee",1800);
  set("eff_kee",1800);
  set("kee",1800);
  set("max_sen",200);
  set("eff_sen",200);
  set("sen",200);  
  set("force",800);
  set("max_force",800);
  set("bellicosity",200);

  set_skill("throwing",60);
  set_skill("parry",60);
  set_skill("dodge",100);
  set_skill("shade-steps",100);
  set_skill("rain-throwing",50);
  map_skill("parry","rain-throwing");
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
  setup();
  ob1=carry_object("/open/killer/obj/lustar");
  ob1->add_amount(200);
  ob1->wield();
  carry_object("/open/killer/weapon/k_arm2.c")->wear();
  carry_object("/open/killer/weapon/k_belt2.c")->wear();
  carry_object("/open/killer/weapon/k_boot2.c")->wear();
  add_money("gold",9);
}
