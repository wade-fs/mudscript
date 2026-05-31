inherit NPC;

string do_ask (object me);

void create()
{
         set_name("顰鬢兒",({"girl"}));
        set("long", "
離子寒的貼身ㄚ環，看起來聰明靈俐，頭上綁著兩條小辮子。 
");
        
        set("age", 15);
        set("int", 30);
        set("cps", 24);
        set("str", 23);
        set("cor", 22);
        set("spi", 29);
        set("con", 26);
        set("kar", 27);
        set("per", 29);
    set("combat_exp",2000);
    set("force",100);
	set("max_force",500);
      set_skill("dodge", 20);
         set_skill("parry", 20);
      set_skill("unarmed",10);


        set( "gender", "女性");


        set("limbs", ({ "頭部",  "雙腳", "雙手", "背部" ,"腹部","腰部"}) );
     
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({
           "顰鬢兒小聲的說:我家姑娘不在這喔...\n",
           "顰鬢兒說道:我家姑娘教我很多東西喔..\n",
        }) );
         set("inquiry",([
        "神兵利器" : "據我所知 , 當今的神兵利器 , 首推倚天劍和屠龍刀 !\n",
     "倚天劍" : "好像在郭襄手中吧,我不知道她在那ㄟ... ?\n",
      "屠龍刀"   : "屠龍刀再謝遜身上啊, 你去找他要 !\n",
          "刀塚" : "嗯 ,那是埋刀之地 ,藏有不少寶刀, 不過沒兩下子的人
   是無法拿到的..\n",
      "囚室" : "嗯, 那裡亂可怕的,我不敢去！ \n",
         "麒麟角" : "這個我也不太清楚, 我家姑娘大概知道吧..\n",
         "鳳凰蛋" :"我家姑娘說過在高大的梧桐樹上居有這種奇獸..\n",
        ]));
    setup ();
 carry_object("/daemon/class/blademan/obj/topknot.c")->wear();
    }
void greeting(object ob)
{

           if( ob->query("gender")=="男性")
        {
          command("say 哇，不要亂走動喔...!");
   }
           if( ob->query("gender")=="女性")
   {
           command("say 妳好阿，大姐姐....^_^");
  }  }
