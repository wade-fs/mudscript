inherit NPC;
string ask_ball()
{
 if(!this_player()->query_temp("swordtime"))
 {
  return ("對不起﹐你問的事我實在沒有印象。");
  }
 else
  {
  if (this_player()->query("class")=="blademan"||this_player()->query_temp("swordquest/findball")==3)
    {
    this_player()->set_temp("swordquest/findball",4);
    return ("嗯....門主騙你的啦﹐他有看過晶珠甌。\n");
   }

else return ("對不起﹐你問的事我實在沒有印象。");
 }
}
void create()
{
	set_name("王福",({"wang fu","wang","fu"}));
	set("long","你看他正匆忙的準備宴席 ,看來 , 又有要客造訪金刀了 .\n");
	set("title","金刀門僕役");
	set("gender","男性");
	set("combat_exp",3000);
        set("attitude","heroism");
	set("age",38);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("unarmed",40);
	set_skill("dodge",30);
	set_skill("parry",30);
        set("inquiry",([
        "夜千鳥晶珠" : (:ask_ball:),
        ]));
	setup();
	add_money("silver",10);
}
 int accept_kill(object me)
 {
  command("angry "+me->query("id"));
   return notify_fail("金刀僕役說道 :要不是有客人來 , 我就宰了你 !\n");
  }
 int accept_fight(object me)
 {
   return notify_fail("金刀僕役說道 :我很忙 , 沒空陪你練功\夫!\n");
 }
