// 這是小渡的標準NPC
inherit NPC;

string to_man();
string to_ask();

void create()
{
  object ob1;

  set_name("渡永天",({"dou_tan","dou","tan"}));
  set("title","黃龍組組長");
  set("long","此人乃殺手的幕後功\臣，殺手有一大堆高手是由此人鍛鍊出來");
  set("gender","男性");
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set("force_factor",10);
  set("age",50);
  set("class","killer");

  set("str", 56);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("con", 55);
  set("kar", 20);

  set("max_gin",200);
  set("eff_gin",200);
  set("gin",200);
  set("max_kee",2200);
  set("eff_kee",2200);
  set("kee",2200);
  set("max_sen",200);
  set("eff_sen",200);
  set("sen",200);  
  set("force",1500);
  set("max_force",1500);
  set("bellicosity",300);

  set_skill("throwing",80);
  set_skill("parry",80);
  set_skill("dodge",80);
  set_skill("shade-steps",80);
  set_skill("rain-throwing",75);
  map_skill("parry","rain-throwing");
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
set("inquiry",([
"追殺者" : (: to_man :),
"歐陽不空" : (: to_ask :),
]));
  setup();
  ob1=carry_object("/open/killer/obj/lustar");
  ob1->add_amount(200);
  ob1->wield();
  carry_object("/open/killer/weapon/k_arm3.c")->wear();
  carry_object("/open/killer/weapon/k_belt2.c")->wear();
  carry_object("/open/killer/weapon/k_cloth2.c")->wear();
  add_money("gold",20);
}

string to_man()
{
  object ob,me;
 
 me=this_player();

 if (me->query_temp("mission3") != 1)
   return "說什麼？我不懂耶";

 tell_object(me,"你想要追殺那個人呀。。。。。嗯。。。。\n");
 tell_object(me,"好吧！我就告訴你，那個人就是無影掌--葉雙\n");
 tell_object(me,"此人武功\非常高強，如果你功\力不夠高，最好不要去找死\n");
 tell_object(me,"這張紙你拿去，順著謎題去找，在某處調查可以找到人指示你\n");
 if (me->query_temp("mission3") != 2)
{
 ob=new("/open/killer/obj/paper1.c");
 ob->move(me);
}
 me->set_temp("mission3",2);
 return "小心一點呀！提示的地點是由此處開始算";
}

string to_ask()
{
  object ob,me;
 
 me=this_player();
 if (me->query_temp("mission3") != 5)
   return "$N說什麼？我不懂耶";
 tell_object(me,"想不到居然被你找到歐陽不空！！\n");
 tell_object(me,"好吧！我就是無影掌--葉雙，好！受死吧！\n");
 set_name("葉雙",({"yar_sha","yar","sha"}));
 set("title","無影掌");
 set("combat_exp",700000); 
 ob=new("/open/killer/obj/yar_head.c");
 ob->move(this_object());
 me->set_temp("mission3",6);
 this_object()->kill_ob(me);
 return "接招！！！";
}
