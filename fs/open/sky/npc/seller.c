#include <ansi.h>
inherit NPC;

string want_help();
string want_help1();
string want_help2();

void create()
{
	set_name("醉問天",({"mystery papt","papt"}));
	set("age",33);
	set("title",HIM + "天靈地界" + HIW + "神祕使者" + NOR);
        set("nickname",HIC + "悠遊靈間" + NOR);
	set("gender","男性");
	set("long",@LONG
    一位悠遊於天地間的神秘人物，喜歡搜集各式各樣的奇珍異寶，尤
其是對天靈地界散落於人間的寶物更是喜愛，所以對於寶物的鑑賞和寶
物的來歷是瞭如指掌，如果你有搜集到了天靈地界中的寶物，而且找不
到一個可靠的人可以託付時，也許可以考慮交給他保管，他除了會細心
的保管外，也可以順便鑑賞天靈地界散落的寶物，所以東西交給他是絕
對安全可靠的。


保 管 費  ：	一樣物品 50 張萬兩銀票
交易方式  ：	pay
取回方式  ：	want
查詢方式  ：	list


LONG);
	set("no_kill",1);
	set("max_kee",1000000);
	set("max_gin",1000000);
	set("max_sen",1000000);
	set("combat_exp",1000000);
	set("int",35);
	set("kar",35);
	set("con",35);

        set("chat_chance", 5);
        set("chat_msg",({

	(: command("sigh") :),
	(: command("say 唉！") :),
	(: command("say 我最近遺失了一樣東西，真是煩惱呀！") :),
        }));

        set("inquiry", ([
	"天靈地界"	:	"是一個神秘的地方，相傳進入的方式只有聚靈山莊的人才知道。",
	"煩惱"		:	(: want_help :),
	"聚靈山莊"	:	(: want_help1 :),
	"困擾"		:	(: want_help2 :),
        ]) );

	setup();
}

void init()
{
	add_action("do_pay","pay");
	add_action("do_want","want");
	add_action("do_list","list");
	add_action("do_nod","nod");
	add_action("do_shake","shake");
}

int do_pay()
{
	object me,ob;
	int coin,i;
	me=this_player();
	i=50000000;
//	coin=(int)me->query("bank/coin");

        if( me->query_temp("quests/sky/pay") ) return notify_fail(HIW + "醉問天說：「別急！別急！一樣一樣慢慢來。」\n" + NOR);
	if( !me->pay_money(i) )
	{
	command("hmm "+me->query("id"));
	message_vision(HIW + "$N的身上沒有足夠的錢付保管費了，請帶了足夠的錢再來找我吧！\n" + NOR,me);
	return 1;
	}
//	if(coin < 50000000 )
//	return notify_fail(HIY + "你目前的存款只剩下" + HIM + "【" + HIW+coin/100000+HIM + "】" + HIY + "張銀票左右而已，不夠 500 張銀票喔。\n" + NOR);
//	coin=coin-50000000;
//	me->set("bank/coin",coin);
	me->set_temp("quests/sky/pay",1);
//	message_vision(HIY + "醉問天說：收到$N" + HIY + "的五百張銀票了，$N" + HIY + "目前的存款還剩下" + HIM + "【 " + HIW+coin/100000+HIM + "】" + HIY + "張銀票左右!!\n" + NOR,me);
	command("smile "+me->query("id"));
	message_vision(HIY + "醉問天說：$N" + HIY + "想保管什麼物品呢？付一次錢只能保管一樣東西喔！\n" + NOR,me);
	return 1;
}

int accept_object(object me,object ob)
{
	string oo,on;
	int os,oa;
	me=this_player();
	oo=ob->query("id");
	on=ob->query("name");
	os=ob->query("specialitem");
	oa=ob->query("magic-manor");
	
	if( !me->query_temp("quests/sky/pay") && me->query_temp("quests/magic-manor-01") )
	{
	  if(me->query_temp("quests/magic-manor-01") == 3 && os != 1 && oa == 1 )
	  {
	  message_vision(HIY + "醉問天說：多謝你幫我找回這樣信物，沒這樣東西，我還真不知道如何回聚靈山莊呢！\n" + NOR,me);
	  me->set_temp("quests/magic-manor-01",4);
	  }else{
	    if(oa == 1)
	    {
	    message_vision(HIY + "醉問天說：哈哈哈.....你怎知這是我要的東西呀？\n" + NOR,me);
	    message_vision(HIY + "醉問天說：既然幫我找回來了，就多謝啦!!\n" + NOR,me);
	    destruct(ob);
	    }else{
	    message_vision(HIY + "醉問天說：$N" + HIY + "沒有付(pay)我金錢，我不會免費幫你保管的「"+ob->query("name")+HIY + "」就當您送給我了。\n" + NOR,me);
	    destruct(ob);
	    return 1;
	    }
	  }
	}else{
	  if( os == 1 )
	  {
	    if( me->query_temp("quests/sky/pay") == 1 )
	    {
	    message_vision(HIY + "醉問天說：交給我保管的東西，就請$N" + HIY + "放一百二十個心吧，絕對妥當!!\n" + NOR,me);
	    me->add("sky/"+oo,1);
	    me->delete_temp("quests/sky/pay");
            write_file("/log/sky/accept",sprintf("%-28s 將 %s 交給醉問天於 %s\n",
            me->name(1)+"("+me->query("id")+")",on,ctime(time())));
	    destruct(ob);
	    }else{
	    message_vision(HIR + "醉問天說：「要我保管東西，總該有一點點的付出吧！」\n" + NOR,me);
	    message_vision(HIR + "只見到醉問天隨手就將" + NOR+ob->query("name")+HIR + "丟了出去！\n" + NOR,me);
	    command("drop "+ob->query("id"));
	    }
	  }else{
	  message_vision(HIY + "醉問天說：「"+ob->query("name")+HIY + "」怎麼看也不像是寶物，不過既然$N送給我了，我就不客氣的收下了 ^^\n" + NOR,me);
	  destruct(ob);
	  }
	}
	return 1;
}

int do_want(string arg)
{
	object me,ob,tb;
	me=this_player();
	ob=this_object();

	if( !arg ) 
	return notify_fail("醉問天道：想要什麼東西也得說清楚呀!!\n");

	switch(arg)
	{
	case "sky-stone":
	case "peace-stone":
	case "emperor-stone":
	case "soil-stone":
	case "loyal-stone":
	case "charity-stone":
	case "justice-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "fire-emblem":
	case "wind-emblem":
	case "ice-emblem":
	case "thunder-emblem":
	case "water-emblem":
	case "soil-emblem":
	case "magic-emblem":
	case "light-emblem":
	case "cloud-emblem":
	case "dark-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
        me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "fire-feather":
	case "water-feather":
	case "soft-feather":
	case "thunder-feather":
	case "light-feather":
	case "wind-feather":
	case "heart-feather":
	case "think-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
        me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "shue-jade":
	case "shen-jade":
	case "hun-jade":
	case "kai-jade":
	case "chen-jade":
	case "uiw-jade":
	case "gii-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "com-shells":
	case "free-shells":
	case "growth-shells":
	case "rigid-shells":
	case "stable-shells":
	case "will-shells":
	case "wish-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
        me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "desert-diamond":
	case "extreme-diamond":
	case "forest-diamond":
	case "meteor-diamond":
	case "moon-diamond":
	case "ocean-diamond":
	case "prairie-diamond":
	case "river-diamond":
	case "sky-diamond":
	case "starry-diamond":
	case "sun-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "dragon-order":
	case "kylin-order":
	case "phoenix-order":
	case "tiger-order":
	case "turtle-order":
	case "deer-order":
	case "fox-order":
	case "roc-order":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj7/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "spring-wind":
	case "summer-wind":
	case "autumn-wind":
	case "winter-wind":
	case "orchid-wind":
	case "bamboo-wind":
	case "plum-wind":
	case "gui-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
        me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "safe-charm":
	case "life-charm":
	case "happy-charm":
	case "happiness-charm":
	case "health-charm":
	case "lucky-charm":
	case "tender-charm":
	case "kind-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
  case "banyan-yin":
  case "birch-yin":
  case "chu-yin":
  case "chun-yin":
  case "cong-yin":
  case "cypress-yin":
  case "elm-yin":
  case "eucalyptus-yin":
  case "fir-yin":
  case "fu-yin":
  case "huai-yin":
  case "kuai-yin":
  case "li-yin":
  case "linden-yin":
  case "maple-yin":
  case "palm-yin":
  case "peach-yin":
  case "pine-yin":
  case "plum-yin":
  case "poplar-yin":
  case "rubber-yin":
  case "sakura-yin":
  case "sandalwood-yin":
  case "surname-yin":
  case "zuo-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
        me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "red-crystal":
	case "black-crystal":
	case "blue-crystal":
	case "green-crystal":
	case "hiblue-crystal":
	case "orange-crystal":
	case "purple-crystal":
	case "white-crystal":
	case "yellow-crystal":

	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj11/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "mango-doll":
	case "apple-doll":
	case "lemon-doll":
	case "guava-doll":
	case "banana-doll":
	case "grapes-doll":
	case "tomato-doll":
	case "cherry-doll":
	case "orange-doll":
	case "litchi-doll":
	case "papaya-doll":
	case "starfruit-doll":
	case "muskmelon-doll":
	case "pineapple-doll":
	case "strawberry-doll":
	case "watermelon-doll":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj12/"+arg);
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
        write_file("/log/sky/want",sprintf("%-28s 跟醉問天要了 %s 於 %s\n",
	me->name(1)+"("+me->query("id")+")",tb->query("name"),ctime(time())));
	me->add("sky/"+arg,-1);
	  if( me->query("sky/"+arg) == 0 )
	  {
	  me->delete("sky/"+arg);
	  }
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	default:
	message_vision("醉問天說：$N是不是記錯啦!!沒有這個東西耶!!\n",me);
	break;
	}
	return 1;

}

int do_list(string arg)
{
	string *obj;
	object me,ob;
	int i,j;
	me=this_player();
	ob=this_object();
	if(!me->query("sky"))
		return notify_fail("你目前目前並沒有在我這兒存放任何東西喔!!\n");
	obj=keys(me->query("sky"));
	if(!arg || arg == "") arg = "all";
        printf("%s存放在我這的寶物如下：\n",me->name());
	for(i=0;i<sizeof(obj);i++)
	{
	if( me->query("sky/"+obj[i])==0 ) continue;
	if(arg != "all" && strsrch(obj[i],"-"+arg) == -1) continue;
	printf(HIM + "【" + HIW + "%-28s" + HIM + "】" + NOR + "共有" + HIM + "【" + HIW + "%2d" + HIM + "】" + NOR + " 個。\n",to_chinese(obj[i])+"("+obj[i]+")",me->query("sky/"+obj[i]));
	}

	return 1;
}

string want_help()
{
	object me;
	me=this_player();

	if( me->query("quests/can_go_magic-manor") )
	{
	me->delete_temp("quests/magic-manor-01");
	command("smile "+me->query("id"));
	return "真是多謝了，謝謝你曾經幫了我這麼一個大忙！";
	}

	else if( me->query_temp("quests/magic-manor-01") == 2 )
	{
	command("bow "+me->query("id"));
	return "一切就多多拜託你了!!";
	}

	else if( me->query("combat_exp") >= 3000000 && !me->query_temp("quests/magic-manor-01") )
	{
	me->set_temp("quests/magic-manor-01",1);
	return "最近我經過一個密林時，被一個神秘飛賊給偷走了一個重要東西!!\n"
	+"	    沒想到那飛賊這麼厲害，連我都無法察覺他偷東西的手法!!\n"
	+"	    沒有那樣東西，我就回不了聚靈山莊了!!\n"
	+"	    您願意幫我一個忙，找回這樣東西嗎？\n";
	}

	else if( me->query_temp("quests/magic-manor-01") >= 4 )
	{
	return "這個還得多謝謝你了，幫我找回這麼重要的東西!!";
	}

	else
	{
	return "我說出來，你也幫不了我的，還是別提了！";
	}
}

string want_help1()
{
	object me;
	me=this_player();
	if( me->query("quests/can_go_magic-manor") )
	{
	return "以後有緣再告訴你吧";
	}

	else if( me->query_temp("quests/magic-manor-01") >= 4 )
	{
	return "唉！別提了，說到這個我才格外的困擾呀！！";
	}

	else
	{
	return "聽說是個江湖上鮮為人知的地方。";
	}
}

string want_help2()
{
	object me;
	me=this_player();

	if( me->query("quests/can_go_magic-manor") )
	{
	me->delete_temp("quests/magic-manor-01");
	command("smile "+me->query("id"));
	return "真是多謝了，幫了我這麼一個大忙！";
	}

	else if( me->query_temp("quests/magic-manor-02") == 1)
	{
	return "我相信，這件事託付給你是正確的選擇!!";
	}

	else if( me->query("combat_exp") >= 3000000 && me->query_temp("quests/magic-manor-01") == 4)
	{
	me->set_temp("quests/magic-manor-01",5);
	return "是這樣的，最近聚靈山莊要傳喚我回去，可是我卻在此分身乏術!!\n"
	+"	    聚靈山莊向來又是不歡迎外人進去，也許\有一個人能幫上此忙。\n"
	+"	    如果願意幫我的話，我可以告訴你有關聚靈山莊的事。\n"
	+"	    您願意再幫我一個忙嗎？\n";
	}

	else
	{
	return "你在說什麼呀？！";
	}
}

int do_nod()
{
	object me = this_player();

	if(me->query_temp("quests/magic-manor-01") != 1 && me->query_temp("quests/magic-manor-01") != 5 )
        return 0;
	if(me->query_temp("quests/magic-manor-01") == 1)
	{
	me->set_temp("quests/magic-manor-01",2);
	remove_call_out("greeting1");
	call_out("greeting1",1,me);
	}else{
	remove_call_out("greeting3");
	call_out("greeting3",3,me);
	}
	return 0;
}

int do_shake()
{
	object me = this_player();
	if(me->query_temp("quests/magic-manor-01") != 1 && me->query_temp("quests/magic-manor-01") != 5 )
        return 0;
	me->delete_temp("magic-manor-01");
	remove_call_out("greeting2");
	call_out("greeting2",1,me);
	return 0;
}

void greeting1(object me)
{
	object ob = this_object();
	command("smile");
	command("say 多謝了，我就在此等你的好消息了 ^^");
}

void greeting2(object me)
{
	command("sigh");
	command("say 雖然你不能幫我，不過還是多謝了！");
	tell_room(environment(this_object()),HIY + "只見到醉問天，低下頭，神情卻顯得落寞。\n" + NOR);
}

void greeting3(object me)
{
	object obj,mob;
	me=this_player();

	command("jump");
	command("say 太好了，有你的幫忙，真是上天莫大的恩賜!!");
	command("say 你可以拿著我的這封信給聖火教主林宏昇，他會幫助你的!!");
	command("say 祝福你了!!");
	message_vision("$N拿到了一封信。\n",me);
	obj=new("/open/magic-manor/obj/letter");
	obj->move(me);
	me->set_temp("quests/magic-manor-02",1);
}
