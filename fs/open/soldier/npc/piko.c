#include <ansi.h>
inherit NPC;
void create()
{
	object ob;
        set_name("皮古",({"pi ko","pi","ko"}));
        set("long","
        他是反亂軍中扮演重要角色之一,反亂軍的武器都是由他
        來打鑄的,他一生中最得意的武器就是雨不沾,當然了還有
        更多厲害兵器都是經過他的手打鑄出來的。

        ");
    set("gender","男性");
        set("title","名鐵匠");
        set("combat_exp",200000);

         set("attitude","heroism");
        set("age",35);
        set("str",30);
        set("cor", 30);
	set("cps", 18);
        set("per", 20);
        set("int", 20);
        set("force",1000);
        set("max_kee",2500);
        set("kee",2500);
	set_skill("parry",50);
        set("max_force",1000);
        set("force_factor",5);
        set_skill("force",50);
        set_skill("unarmed",40);
        set_skill("lance",50);
        set_skill("power-lance",50);
	set_skill("dodge",50);
        set_skill("parry",40);
        set_skill("eagle-steps",30);
        map_skill("lance","power-lance");
        map_skill("dodge","eagle-steps");
        map_skill("parry","power-lance");
        set_skill("spforce",30);
        map_skill("force","spforce");
        set("list",([
        "木槍": ([
                "local":"/open/soldier/obj/wood",
                  "amount":20,
                "id":"wood",
                ]),
        "長槍": ([
                "local":"/open/soldier/obj/long",
                "amount":10,
                "id":"long",
                ]),
        "蛇戢":([
                "local":"/open/soldier/obj/snake",
                "amount": 5,
                "id":"snake",
                ]),
       "獸矛":([
                "local":"/open/soldier/obj/beast",
                "amount": 3,
                "id":"beast",
             ]), 
        ]));
	setup();
        ob=carry_object("/open/soldier/obj/soak");
        ob->wield();
}

void init()
{
	add_action("do_list","list");
        add_action("do_receive","receive");
}
int do_list(object me)
{
	string *name;
	int i;
        me=this_player();
        name=keys(query("list"));
        tell_object(this_player(),"現在所製造出來的武器數量:\n");
	for(i=0;i<sizeof(name);i++)
        tell_object(this_player(),sprintf("%10s%10d\n",name[i],query("list/"+name[i]+"/amount")));
	return 1;
}
int do_receive(string weapon)
{
	object ob;
        ob=this_player();
        if(this_player()->query("class")!="soldier")
	{
                command("say 你誰ㄚ !! 我怎麼沒看過你。\n");
		return 1;
	}
	if(!query("list/"+weapon))
	{
		command("say 你想要什麼武器 ?\n");
		return 1;
	}
	if(present(query("list/"+weapon+"/id"),this_player()))
	{
                command("say 武器用壞了再來拿。\n");
		return 1;
	}
	if(query("list/"+weapon+"/amount")<=0)
	{
                command("say 你沒看到我在趕ㄚ。\n");
		return 1;
	}

      if(query("list/"+weapon+"/id")=="long",this_player())
      {
         if (ob->query("combat_exp")<=500 ) 
         {
               command("say 你的磨練不夠來向我拿長槍。\n");
               return 0;
         }
      }
      if(query("list/"+weapon+"/id")=="snake",this_player())
      {
         if (ob->query("combat_exp")<=5000 ) 
         {
               command("say 你的磨練不夠來向我拿蛇戢。\n");
               return 0;
         }
      }
      if(query("list/"+weapon+"/id")=="beast",this_player())
      {
         if (ob->query("combat_exp")<=35000 ) 
         {
               command("say 你的磨練不夠來向我拿獸矛。\n");
               return 0;
         }
      }
       
	ob=new(query("list/"+weapon+"/local"));
        ob->add_amount(2);
        add("list/"+weapon+"/amount",-1);
	ob->move(this_player());
	ob->set("no_drop",1);
	ob->set("no_give",1);
        message_vision( "$N拿給$n一把"+ob->name()+"\n",this_object(),this_player());
	return 1;
} 
