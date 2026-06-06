inherit NPC;
string do_ask();
string do_ask_bo();

void create()
{
	set_name("盜賊",({"bandit"}));
	set("long","賊頭賊腦的 ,一看就知道決非善類 ,手裡拿了個大包包 !\n");
	set("gender","男性");
	set("combat_exp",723);
	set("attitude","friendly");
        set("age",25);
	set("class","bandit");
	set("str", 30);
        set("cor", 30);
        set("per", 15);
        set("int", 15);
	set("cps", 30);
	set("con", 30);
        set("kar", 20);
        set_skill("dodge",30);
	set_skill("dagger",30);
        set_skill("parry",20);
	set("inquiry",([
	"展伯承" : (:do_ask_bo:),
	"包包" : "奇怪 ,你管我包包放什 ?",
	"東西" : "就是一幅畫咩 !",
	"畫" : (:do_ask:)
	]));
	setup();
        carry_object("/obj/example/dagger.c")->wield();
}
   void init()
  {
   add_action("do_nod","nod");
  }
     int do_nod(string str)
  {
   object me;
   me=this_player();
  if(!me->query_temp("can_buy_picture"))
  {
    return 0;
   }
   if(me->query("quests/bochen_trouble")||me->query_temp("have_buy_picture"))
  {
  command("say 畫已經賣給你啦 !");
	return 1;
  }
    if(me->can_afford(1000)!=1)
  {
   command("say 他奶奶的 ,敢耍老子 !");
	this_object()->kill_ob(me);

	return 1;
   }
   me->pay_money(1000);
  me->set_temp("have_buy_picture",1);
  new("/open/gblade/obj/picture")->move(me);
   message_vision("$N付了錢 ,盜賊打開包包 ,取出名畫交給$N\n",me);
   command("smile "+me->query("id"));
  command("say 感謝你的捧場 !");
	me->delete_temp("know-bo");
   return 1;
 }
   string do_ask_bo()
   {
	this_player()->set_temp("know-bo",1);
	return "哈哈 ! 被我偷了東西還不知道的笨蛋 !";
    }

 string do_ask()
  {
	if(!this_player()->query_temp("know-bo"))
	return "什麼畫啊 ? 我不知道你在說什 ?";
	this_player()->set_temp("can_buy_picture",1);
   command("say 我是粗人 ,不會欣賞 ,今天算你運氣好 !");
    return "賣你十兩銀子 ,要不要 ?";
  }
