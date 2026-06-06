inherit NPC;
#include <ansi.h>
string ask();
string do_work();

void create()
{
	set_name("鈺萍姊",({"woman"}));
	set("long","
她是在琰揚居服侍水邪將--水柔纏的邪靈之一，一雙碧綠色的大
眼，水藍色的秀髮，雖然歲月不斷的在她臉上留下了痕跡，可是
卻無損她那迷人的臉龐，你看她忙的不可開交的樣子，或許\你能
幫忙她做一些雜事吧。\n");
	set("age",10291);
	set("gender","女性");
	set("inquiry",([
		"幫忙":(: ask :),
		"水邪將":"唉...別問了...那是一個慘忍的封號...\n",
		"水柔纏":"唉...她是我的主子，你如果想見她，可能很難...除非...\n",
		"除非":"除非你能假裝這裡的傭人，先幫忙我做廚房的工作...藉機混進主人的房內..\n",
	]));
	set("chat_chance",10);
	set("chat_msg",({
	(: do_work :),
	}));
setup();
}

int accept_object(object me,object ob)
{
int i,j;

	if( !me->query_temp("evil/water/mission") )
		return 0;

	i = (int)me->query_temp("evil/water/mission");

	if( i == 1 )
	{
		if( !me->query_temp("evil/water/f_mission-1") )
			(int)me->set_temp("evil/water/f_mission-1",1);

		j = (int)me->query_temp("evil/water/f_mission-1");

		if( ob->query("id") == "good torch" )
		{
			if( j > 5 )
			{
			command("say 嗯～這樣就夠多了～應該可以燒出一手好菜出來了～\n");
			command("say 不過...還是有事情需要你的幫忙...^-^\n");
			command("grin "+me->query("id"));
			me->delete_temp("evil/water/f_mission-1");
			(int)me->set_temp("evil/water/mission",2);
			}
			else
			{
			command("say 嗯～辛苦你了～不過木材還不夠...\n");
			command("say 請你再多拿點燃木材去砍來給我...拜託了..^-^\n");
			command("rub "+me->query("id"));
			(int)me->add_temp("evil/water/f_mission-1",1);
			me->set_temp("evil/water/ask-mission-1",1);
			}
		}

		if( ob->query("id") == "bad torch" )
		{
			command("say ㄟ...如果可以...我是說...希望你能做好一點。\n");
			command("say 這根無法做出好吃的食物出來...所以..請你再去幫我砍一些好的燃木材。\n");
			me->set_temp("evil/water/ask-mission-1",1);
		}
	}
	call_out("do_dest",1,ob);
return 1;
}

int do_dest(object ob)
{
destruct(ob);
}

string do_work()
{
object ob = this_object();
	
	if( !ob->query_temp("move_action") )
	{
		command("say 唉唉...油鍋又過熱了...趕緊過去翻動一下鍋子..\n");
		command("north");
		message_vision("$N不斷的翻動著鍋面。\n",ob);
		ob->set_temp("move_action","north");
	}
	else
	{
		if( ob->query_temp("move_action") == "north" )
		{
			command("say 是誰又把炊坎的器具亂放了...真是的...\n");
			command("west");
			ob->set_temp("move_action","west");
			message_vision("$N不斷的整理著凌亂的炊坎器具。\n",ob);
		}
		else if( ob->query_temp("move_action") == "west" )
		{
			command("say 是誰將我剛剛刷過的木材又弄髒了...\n");
			command("say 難道沒人知道乾淨的木材燒出來的食物會比較好吃的嗎!?\n");
			ob->set_temp("move_action","south");
			command("south");
			message_vision("$N不斷的刷洗著地上的木材。\n",ob);
		}
		else if( ob->query_temp("move_action") == "south" )
		{
			command("say 嗯...食物放置於桌上不曉得有沒有壞掉的...\n");
			ob->set_temp("move_action","east");
			command("east");
			message_vision("$N品嚐著桌上鮮美的食物。\n",ob);
		}
		else if( ob->query_temp("move_action") == "east" )
		{
			command("say 唉唉...油鍋又過熱了...趕緊過去翻動一下鍋子..\n");
			ob->set_temp("move_action","north");
			command("north");
			message_vision("$N不斷的翻動著鍋面。\n",ob);
		}
	}
return "真是忙啊...\n";
}

string ask()
{
object me,ob,obj;
int i,j;

	me = this_player();
	ob = this_object();

	if( !me->query_temp("evil/water/mission") )
		(int)me->set_temp("evil/water/mission",1);

	i = (int)me->query_temp("evil/water/mission");
	me->set_temp("evil/water/ask-mission-"+i,1);
	switch(i)
	{
		case 1:	
			{
			command("say 首先你先去廚房內找尋燃木材..將燃木材拿到後廂房那的一塊空地上。\n");
			command("say 將其劈開然後再拿來給我。\n");
			break;
			}
		case 2:
			{
			command("say 再來你從廚房內找出一推棉草，拿到後廂房餵食那隻凶暴的金錦馬。\n");
			command("say 小心別被它踢傷了...除了主人餵它，不然一般魔獸餵食它，都很容易被它踹飛。\n");
			break;
			}
		case 3:
			{
			command("say 奇怪了...我不曉得我將廚房內的千花蜜放到哪去了...\n");
			command("say 如果你找到的話，記得幫我將千花蜜拿去餵食鼓蜂....\n");
			command("say 對了...鼓蜂就在後廂房的那棵大松樹上，小心別被螫了。\n");
			break;
			}
		case 4:
			{
			command("say 嗯...好不容易煮好了一些食物，都放在桌上了。\n");
			command("south");
			command("east");
			ob->delete_temp("move_action");
			j = random(5)+1;
			obj = new(__DIR__"obj/food"+j);
			tell_object(me,"你看到鈺萍姊走向放置食物的桌子上，從桌上端了一盤"+obj->name(1)+"給你。\n");
			tell_object(me,"鈺萍姊告訴你說：請幫我端到後廂房給我的主子，想必她應該已經覺得餓了。\n",ob);
			break;
			}
	}
return "好了，就這樣...快去快回吧...廚房很忙的...\n";
}

