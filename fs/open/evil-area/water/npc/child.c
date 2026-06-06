inherit NPC;
#include <ansi.h>
string play();
int do_dest();

void create()
{
	set_name("卞慶兒",({"child"}));
	set("long","
一個好玩的小孩子，不過似乎跟別人玩的不太一樣。\n");
	set("gender","男性");
	set("age",12019);
	set_skill("unarmed",100);
	set_skill("move",100);
	set_skill("dodge",100);
	set_skill("force",100);
	set("inquiry",([
		"玩":(: play :),
		"水柔纏":"她是我媽媽啊～它可是管理這的人ㄝ～很偉大吧！^o^\n",
                "邪靈界":"邪靈界??...邪靈界不就是這裡嗎??..你怎麼問這麼奇怪的問題??\n",
		"媽媽":"水邪將就是我媽媽啊～我很了不起吧! ^-^\n",
		"水邪將":"我只知道水邪將就是我媽媽ㄝ...其它的我就不知道了...你陪不陪我玩啊\n",
	]));
setup();
}

void init()
{
object me,ob;

	me = this_player();
	ob = this_object();

	if( ob->query_temp("evil/water/catch_id") == me->query("id") )
		add_action("do_catch","catch");
}

int do_catch()
{
object me,ob;
int i;

	me = this_player();
	ob = this_object();

	(int)me->add_temp("evil/water/catch_times",1);
	if( (int)me->query_temp("evil/water/catch_times") > 5 )
	{
		command("say 哈哈～～我玩的好累了～你真厲害ㄝ～都找的到我。");
		message_vision("$N露出心滿意足的表情，顯然對於剛剛的遊戲，玩的很盡興了。\n",ob);
		command("say 好吧～我說過了，如果你找的到我，我帶你去一個好地方，走吧！");
		message_vision("$N拉著$n的手，狂奔了出去。\n",ob,me);
		me->move("/open/evil-area/water/b-01");
		ob->move("/open/evil-area/water/b-01");
		me->delete_temp("evil/water/catch_times");
		message_vision("$n被$N帶到了琰揚居內。

$N說：嗚ㄣ～～人家累了...要去睡了...zzz\n",ob,me);
		message_vision("$N說完，顧自的伸伸懶腰，走進了臥室內休息了。\n",ob);
		do_dest();
	}
	else
	{
		command("say 哇～好厲害喔～很少有人找的到我說～我們再玩一次!!\n");
		message_vision("$N一說完，又溜的不見人影了...留下了尚未會意過來的$n...\n",ob,me);
		i = random(31)+1;
		if( i < 10 )
			ob->move("/open/evil-area/water/a-0"+i);
		else
			ob->move("/open/evil-area/water/a-"+i);
		ob->set_temp("evil/water/hide",1);
		ob->set_temp("evil/water/catch_id",me->query("id"));
		message_vision(HIB"$N偷偷的說：嗯...這次應該不會被找到了吧...^c^\n"NOR,ob);
	}
return 1;
}


void greeting(object ob)
{
object obj;

	obj = this_object();

        if( !ob || environment(ob) != environment() )
		return;

	if( obj->query_temp("evil/water/hide") )
	{
		if( ob->query("id") == obj->query_temp("evil/water/catch_id") )
			message_vision("$N看到$n，急忙的找地方藏匿～\n",obj,ob);
		else
			command("say 噓...不要跟別人說我在這裡喔...\n");
	}
	else
	{
	if( ob->query_temp("evil/water/killed") )
		command("say 你是壞人，我聞的到你身上有血腥味。\n");
	else
		command("say 陪我玩好嗎?..我好無聊喔～\n");
	}
}

string play()
{
object me,ob;
int i;

	me = this_player();
	ob = this_object();

	if( ob->query_temp("evil/water/hide") )
		return "人家現在沒空陪你玩啦～走開走開啦～\n";
	
	if( !me->query_temp("evil/water/killed") )
	{
	message_vision("$N說：好吧～那我就跟你說...說完了我們就開始玩了喔...\n",ob);
	message_vision("
$N說：就是玩躲貓貓啊～我會去藏起來，如果你抓到(catch)我的話，那我就帶你去一個好地方喔～好了..

"HIY"			開		始		!!!\n\n"NOR,ob);
	i = random(31)+1;
	if( i < 10 )
		ob->move("/open/evil-area/water/a-0"+i);
	else
		ob->move("/open/evil-area/water/a-"+i);
	ob->set_temp("evil/water/hide",1);
	ob->set_temp("evil/water/catch_id",me->query("id"));
	call_out("do_check",120,ob);
	return "記得來抓(catch)我喔～如果超過了兩分鐘你還抓不到我就算你輸了。\n";
	}
	else
		return "算了...你身上有血腥味，媽媽說不能跟那種人玩..\n";
}

int do_check()
{
object ob = this_object();
	command("say "+ob->query_temp("evil/water/catch_id")+"好笨喔...都抓不到我...算了...人家不玩了。\n");
	command("tell "+ob->query_temp("evil/water/catch_id")+" 人家不玩了啦...你都抓不到人家～哼!!\n");
	do_dest();
return 1;
}

int do_dest()
{
object ob = this_object();
	destruct(ob);
}
