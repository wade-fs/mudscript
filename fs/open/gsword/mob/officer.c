// guard.c
//改變greeting的判定以避開錯誤訊息 by blazakira 2011/6/4

inherit NPC;

void create()
{
  set_name("稅官", ({ "officer" }) );
  set("gender", "男性" );
  set("age", 37);
  set("str", 50);
  set("cor", 65);
  set("long",
    "一位負責執行本朝財政命命的官員.\n"
    "他正執行貨幣流通控制.你可以查詢你的\n"
    "存款上限(quota).\n" );
  set("combat_exp", 50000);
  set("attitude","peaceful");
  set("force",1000);
  set("max_force",1000);
  set("force_factor",10);
  set_skill("parry", 3);
  set_skill("dodge", 3);
  set_skill("unarmed",85);
  set_skill("gold-blade",40);
  set_skill("fly-steps",3);
  map_skill("blade","gold-blade");
  map_skill("dodge","fly-steps");
  map_skill("parry","gold-blade"); 
  setup();
  add_money("silver", 1);
  carry_object("/open/gblade/obj/blade")->wield();
  carry_object("/open/ping/obj/chainmail")->wear();
  carry_object("/open/gsword/obj/legging")->wear();
}

void init()
{  
  object ob;
  add_action("do_quota","quota");
  ::init();
  if(interactive(ob =this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting",2,ob);
  }
}

int do_quota(string arg)
{
  int mud_age;
  mud_age = this_player()->query("mud_age");
  printf("稅官說: 老爺,您的存款上限是 %d coins\n",mud_age);
  return 1;
}

void greeting(object ob)
{
  object obj;
  int money,mud_age,silver,lend;
  if( !ob || environment(ob) != environment() ) return;
  obj=present("no_tax",ob);
  if( obj ) return;
  money = ob->query("bank/coin");
  silver = ob->query("bank/silver");
  mud_age = ob->query("mud_age");
  lend = ob->query("bank/lend");
  command("say hi...老爺你好.\n");
  if(money > mud_age)
  {
    money = (money * 0.5);
    if( (silver%2) == 0 ) {
      silver /= 2;
      ob->set("bank/coin", money);
      ob->set("bank/sliver", silver);
    }
    else {
      silver = (silver-1) / 2;
    }
    command("say 抱歉了,大財主,奉朝庭聖旨,凡財產大於上線秒數者,一律一半充公.\n");
  }

  if(lend >=50000)
  {
    money = (money * 0.75);

    if( (silver%4*3) == 0 ) {
      silver /= 4*3;
      ob->set("bank/coin", money);
      ob->set("bank/sliver", silver);
    }
    else {
      silver = (silver-1) /4*3 ;
    }
    command("say 抱歉了 老爺, 欠錢莊的錢請儘快還, 不然利息可是累加的喔.\n");
  }
}
