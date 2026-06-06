// 這是小渡的標準NPC
inherit NPC;

string to_man();
string to_ask();

void create()
{
  object ob1;

  set_name("楊小七",({"siu-chi","siu","chi"}));
  set("title","紫霞組組長");
  set("long","此人並非殺手出身，純粹是因為楊小邪的一句話，就決定擔下保護天靈老人的工作");
  set("gender","男性");
  set("combat_exp",1500000); 
  set("attitude","friendly");
  set("force_factor",10);
  set("age",26);
  set("class","killer");
  set("quest/rain",1);
  set("str", 77);
  set("int", 30);
  set("spi", 30);
  set("cps", 30);
  set("con", 55);
  set("kar", 30);
  set("max_gin",500);
  set("eff_gin",500);
  set("gin",500);
  set("max_kee",3200);
  set("eff_kee",3200);
  set("kee",3200);
  set("max_sen",500);
  set("eff_sen",500);
  set("sen",500);  
  set("force",2500);
  set("max_force",2500);
  set("bellicosity",500);

  set_skill("throwing",80);
  set_skill("parry",100);
  set_skill("dodge",70);
  set_skill("shade-steps",70);
  set_skill("rain-throwing",75);
  map_skill("parry","rain-throwing");
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
set("inquiry",([
"楊小邪" : "他是我最要好的朋友，沒有他就沒有今天的我",
"歐陽不空" : "他是楊小邪的師傅",
]));
set("chat_chance_combat",50);
set("chat_msg_combat",({
(:perform_action,"throwing.manakee":),
}));
  setup();
  ob1=carry_object("/open/killer/obj/lustar");
  ob1->add_amount(999);
  ob1->wield();
  carry_object("/open/killer/weapon/k_arm3.c")->wear();
  carry_object("/open/killer/weapon/k_belt2.c")->wear();
  carry_object("/open/killer/weapon/k_cloth2.c")->wear();
  add_money("gold",30);
}
