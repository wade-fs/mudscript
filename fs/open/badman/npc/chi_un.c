inherit NPC;
void create()
{
        set_name("秦雲", ({ "chi un","chi","un" }) );
        set("class","badman");
        set("gender", "男性" );
        set("age", 45);
        set("long", "一臉尖嘴猴腮樣，因做了一件虧\n心事而躲入惡人谷，不過卻很少\n人知道他為何躲入谷內。\n");
        set("combat_exp",100000);
        set("max_kee",5000);
        set("kee",5000);
        set("max_sen",1500);
        set("sen",1500);
        set("max_gin",1500);
        set("gin",1500); 
        set("max_force",4000);
        set("force",4000);
        set("force_factor",10);
        set("bellicosity",2000);
        set("title","鎮關東");
//        set("functions//level",30);
        set_skill("parry",80);
        set_skill("dodge",60);
        set_skill("sword",80);
        set_skill("badsword",100);
        set_skill("ghost-steps",100);
        set_skill("force",100);
        set_skill("badforce",200);
        map_skill("dodge","ghost-steps");
        map_skill("force","badforce");
        map_skill("sword","badsword");
        map_skill("parry","badsword");
        set_temp("apply/attack",40);
        set_temp("apply/armor",40);
        set_temp("apply/dodge",40); 
        set("inquiry",([
"虧心事" : "誰沒做過虧心事ㄚ，我躲入谷中只是要幹一件大事誰知....",
"誰知" : "誰知我千辛萬苦偷來的書卻又被偷了，小兄弟能幫我找回嗎??",
"找回" : "好!!只要你幫我找回那本書，我就授你魔日劍法!!",
"書" : "那本書就是記載著我一身武學的魔日劍譜，你找到後也可自行修練",
"魔日劍譜" : "那本書就是記載著我一身武學的魔日劍譜，你找到後也可自行修練",
"魔日劍法" : "魔日劍法就是我縱橫武林的武學，找回書我就教你",
]));
//        set("chat_msg_combat",({(: perform_action,"" :)}));
        setup();
        carry_object("/open/gsword/obj/sword.c")->wield();
}
void init()
{
  add_action("do_verify","verify");
}
int accept_object(object me, object obj)
{
if(me->query("class") != "bandit") return 0;
        if( obj->query("name") == "魔日劍譜" )
          {
          command("pat "+getuid(me));
          command("say 哇～厲害厲害！竟能幫我找回魔日劍譜。");
         if( me->query_temp("get_badsword_book",1))
  {
          command("say 既然你幫我找回了魔日劍譜，照約定我就傳你魔日劍法吧。");
          me->set("get_badsword",1);
          command("say 已傳你部份劍法了，其他就從書上自己學習了。");
          command("say 要書就直接跟我要(verify book)吧");
          command("say 或者去跟司馬煙學(llearn)習劍法");
  }
       else 
  {
       command("say 這不是你自己尋回來的！想騙我！！");
  }
          }
}
int do_verify(string arg)
{
object me,ob;
me=this_player();
ob=new("/open/badman/obj/sword_book.c");
 if( arg!="book")
   {
    command("say 你要什麼東西？");
    return 1;
   }
if(me->query("get_badsword")!= 1)
      {
    command("say 你又沒幫我找回書，我怎麼給你ㄚ？");
    return 1;
      }
if (present("badsword book", me))
       {
    command("say 你已經有了不是嗎？");
      return 1;
       }
   else
        {
    command("say 好好練吧！");
    ob->move(me);
         return 1;

        }
}
