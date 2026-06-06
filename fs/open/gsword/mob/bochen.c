//展伯承 make by wugi
inherit NPC;
string ask_test();
void create()
{
	set_name("展伯承",({"bo chen","bo","chen"}));
	set("gender","男性");
	set("age",25);
	set("class","blademan");
	set("str",25);
        set("long","金刀弟子 ,看他神色慌張 ,不知在(找尋)什麼東西 ?\n");
	set("combat_exp",20000);
	set_skill("blade",40);
	set_skill("parry",40);
	set_skill("dodge",40);
	set_skill("gold-blade",50);
	set_skill("fly-steps",50);
	set_skill("sixforce",40);
	map_skill("blade","gold-blade");
	map_skill("dodge","fly-steps");
	map_skill("move","fly-steps");
	map_skill("parry","gold-blade");
	map_skill("force","sixforce");
	set("chat_chance",10);
	set("chat_msg",({
		"展伯承到處看來看去 ,神色甚是慌張.\n",
		"展伯承說道 : 完蛋啦 ,怎麼向師父交代呢 ?\n"
		}));
	set("inquiry",([
	"找尋" : "師父命我送幅(名畫)給仙劍鄭掌門賀壽 ,昨天在(投宿)時 ,卻被偷了 .\n",
    "試煉印記" : (:ask_test:),
	"名畫" : "那是北宋范寬的名作啊 !\n",
	"投宿" : "我是住在蜀中城東的一家客棧 ,唉 , 都怪我不小心 .\n",
	]));
	setup();
	create_family("金刀門",6,"弟子");
	carry_object("/open/gblade/obj/blade1")->wield();
	add_money("gold",10);
}



int accept_fight(object who)
{
return notify_fail("展伯承說道 : 你沒看到我很忙嗎。\n");
}


int accept_object(object me,object ob)
{
  if(ob->query("id")=="picture")
   {
	if(me->query("quests/bochen_trouble"))
      {
       command("say 上次真多謝你的幫忙 !");
       return 1;
      }
    if(me->query("family/family_name")!="金刀門")
    {
      command("thank "+me->query("id"));
      me->set("quests/bochen_trouble",1);
      new("/obj/money/gold")->move(me);
      me->add("combat_exp",100);
      message_vision("展伯承取出一錠黃金 ,交給$N !\n",me);
      command("say 小小黃金 ,不成敬意 ,以後金刀門永當你是客!");
    }
 else {
	command("smile "+me->query("id"));
	if(me->query("gender")=="男性")
	command("say 小師弟 ,不簡單喔 !");
	if(me->query("gender")=="女性")
        command("say 小師妹 ,真是女中豪傑 !");
	me->set("quests/bochen_trouble",1);
	new("/obj/money/gold")->move(me);
	me->add("combat_exp",500);
	message_vision("展伯承取出一錠黃金 ,交給$N !\n",me);
	command("say 為了報答你 ,師兄教你幾手 !");
	tell_object(me,"聽了展伯承的教導 ,你覺的自己似忽進步了不少 !\n");
	}
  return 1;
    }
}
string ask_test()
{
if(this_player()->query("quests/yan")==3)
{
 if(this_player()->query("quests/bochen_trouble",1)&&this_player()->query("quests/2ndtest")<1)
{
int i;
i=random(3)+1;
command("say 謝謝你之前的幫忙.我願意將我我手上的試煉印記傳到你身上!\n");
this_player()->set("quests/2ndtest",i);
this_player()->set("quests/yantestmark1",1);
return("不過..剩下的印記..你就要尋遍整個狂想大陸.但是我可以瞞著appo 偷偷跟你說.其實..他都把印記藏在狂想quest人物的身上..你可以打(quest)看看有哪些地方比較有可能\n");
}
 else if (this_player()->query("quests/2ndtest")!=0)
  return ("我已經把印記給你了..你還要做什麼\n");
 else
return ("裝校維..你都不知道我的煩惱..還想要印記!!\n");
}
else 
return ("啥印記..你在說什麼?\n");
}
