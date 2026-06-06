//橋邊人

inherit NPC;
string do_act();
string do_acc();
string ask_tesin();

void create()
{
        set_name("橋邊人",({"man"}));
        set("gender","男性");
        set("age",50);
        set("class","blademan");
        set("str",10);
   set("long"," .\n");
        set("chat_chance",10);
        set("chat_msg",({
                "橋邊人說:我好痛苦。\n"
                  }));

        set("inquiry",([
         "燈火" : (:do_act:) ,
         "回家" : (:do_acc:) ,
         "龍鐵心" : (:ask_tesin:),
                      ]));
        add_action("do_act","act");
        add_action("do_acc","acc");
        set("combat_exp",1000000);
        setup();
        add_money("silver",1);
}
int accept_fight(object who)
{
 return notify_fail("橋邊人說:我已夠可憐了，還想要我打啊。\n");
}
void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting())

        {
        remove_call_out("greeting");
        call_out("greeting",2,obj);

                }
}
void greeting(object ob)
{
        command("think");
}
  string do_act()
{
        command("say 我就是被炎龍佔據村落的居民。 ");
        command("say 炎龍看我強壯要我在這橋旁提著燈。");
        command("say 說是要替人打開死亡之道。");
        command("say 我還聽說這橋有問題喔!");

 }
  string do_acc()
{
    command("say 咦?我以前是道士的事,怎麼傳出去了?");
    command("say 罷了.既然你已經知道了,就幫助你吧!");
    this_player()->move("/u/p/poloer/dragon/enterroom.c");
}
string ask_tesin()
 {
if (!this_player()->query_temp("find_tesin4"))
  {
  this_player()->set_temp("find_tesin5",1);
  return ("龍鐵心?在我到這之前..他早就不在了.");
  }
else if (this_player()->query_temp("find_tesin4")==1)
  {
  this_player()->set_temp("find_tesin5",2);
  return ("龍鐵心?在我到這之前..他早就不在了.");
  }
else if (this_player()->query_temp("find_tesin4")==2)
   {
  this_player()->set_temp("find_tesin5",3);
  return ("龍鐵心?在我到這之前..他早就不在了.");
  }

}

void heart_beat()
{
        if( random(5) < 2 ){
        if(!is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
            if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
                           }
        }
        :: heart_beat();
}       
