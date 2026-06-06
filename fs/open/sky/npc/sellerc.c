#include <ansi.h>
inherit NPC;

void create()
{
	set_name("醉問天",({"mystery seller","seller"}));
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


保 管 費  ：	一樣物品 500 張銀票
交易方式  ：	pay	(直接從存款裏扣)
取回方式  ：	want
查詢方式  ：	list


LONG);
	set("no_kill",1);
	set("max_kee",1000000);
	set("combat_exp",10000);
	set("int",35);
	set("kar",35);
	set("con",35);
	setup();
}

void init()
{
	add_action("do_pay","pay");
	add_action("do_want","want");
	add_action("do_list","list");
}

int do_pay()
{
	object me,ob;
	int coin;
	me=this_player();
	ob=this_object();
	coin=(int)me->query("bank/coin");

	if(coin < 50000000 )
	return notify_fail(HIY + "你目前的存款只剩下" + HIM + "【"HIW+coin/100000+HIM"】" + HIY + "張銀票左右而已，不夠 500 張銀票喔。\n" + NOR);

	coin=coin-50000000;
	me->set("bank/coin",coin);
	me->set_temp("quests/sky/pay",1);
	message_vision(HIY + "醉問天說：收到$N" + HIY + "的五百張銀票了，$N" + HIY + "目前的存款還剩下" + HIM + "【 "HIW+coin/100000+HIM"】" + HIY + "張銀票左右!!\n" + NOR,me);
	command("smile "+me->query("id"));
	message_vision(HIY + "醉問天說：$N" + HIY + "想保管什麼物品呢？付一次錢只能保管一樣東西喔！\n" + NOR,me);
	return 1;
}

int accept_object(object me,object ob)
{
	string oo,on;
	int os;
	me=this_player();
	oo=ob->query("id");
	os=ob->query("specialitem");

	if( !me->query_temp("quests/sky/pay") )
	{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有付(pay)我金錢，我不會免費幫你保管的「"+ob->query("name")+HIY"」就當您送給我了。\n" + NOR,me);
	destruct(ob);
	return 1;
	}
	if( os == 1 )
	{
	message_vision(HIY + "醉問天說：交給我保管的東西，就請$N" + HIY + "放一百二十個心吧，絕對妥當!!\n" + NOR,me);
	me->add("sky/"+oo,1);
	me->delete_temp("quests/sky/pay");
	destruct(ob);
	}else{
	message_vision(HIY + "醉問天說：「"+ob->query("name")+HIY"」怎麼看也不像是寶物，不過既然$N送給我了，我就不客氣的收下了 ^^\n" + NOR,me);
	destruct(ob);
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
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/sky_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "peace-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/peace_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "emperor-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/emperor_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "神醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "soil-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/soil_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "loyal-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/loyal_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "charity-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/charity_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "justice-stone":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj2/justice_stone");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "fire-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/fire_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "wind-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/wind_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
//1
	case "wind emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/wind_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	me->delete("sky/wind emblem");
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
//1
	case "ice-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/ice_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "thunder-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/thunder_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "water-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/water_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "神醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "soil-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/soil_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "magic-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/magic_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "light-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/light_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "cloud-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/cloud_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "dark-emblem":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj1/dark_emblem");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "fire-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/fire_feather");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "water-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/water_feather");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "soft-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/soft_feather");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "thunder-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/thunder_feather");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "light-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/light_feather");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "wind-feather":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj3/wind_feather");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "shue-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/shue_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "shen-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/shen_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "hun-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/hun_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "kai-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/kai_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "chen-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/chen_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "uiw-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/uiw_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "gii-jade":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj5/gii_jade");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "com-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/com_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "free-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/free_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "growth-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/growth_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "rigid-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/rigid_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "stable-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/stable_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "will-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/will_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "wish-shells":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj4/wish_shells");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "desert-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/desert_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "extreme-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/extreme_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "forest-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/forest_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "meteor-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/meteor_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "moon-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/moon_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "ocean-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/ocean_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "prairie-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/prairie_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "river-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/river_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "sky-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/sky_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "starry-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/starry_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "sun-diamond":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj6/sun_diamond");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "dragon-order":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj7/dragon_order");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "kylin-order":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj7/kylin_order");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "phoenix-order":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj7/phoenix_order");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "tiger-order":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj7/tiger_order");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "turtle-order":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj7/turtle_order");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "spring-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/spring_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "summer-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/summer_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "autumn-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/autumn_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "winter-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/winter_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "plum-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/plum_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "orchid-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/orchid_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "bamboo-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/bamboo_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "gui-wind":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj8/gui_wind");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "safe-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/safe_charm");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "life-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/life_charm");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "happy-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/happy_charm");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "happiness-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/happiness_charm");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "health-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/health_charm");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "lucky-charm":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj9/lucky_charm");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "peach-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/peach_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
//3
	case "peach yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/peach_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	me->delete("sky/peach yin");
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
//3
	case "surname-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/surname_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "maple-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/maple_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
//4
	case "maple yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/maple_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	me->delete("sky/maple yin");
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;
//4
	case "cypress-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/cypress_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "pine-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/pine_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "plum-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/plum_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "banyan-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/banyan_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "fir-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/fir_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
	}else{
	message_vision(HIY + "醉問天說：$N" + HIY + "沒有在我這裏寄放這樣東西吧？\n" + NOR,me);
	}
	break;

	case "palm-yin":
	if( me->query("sky/"+arg) && me->query("sky/"+arg) > 0 )
	{
	tb=new("/open/sky/obj10/palm_yin");
	tb->move(me);
	message_vision("醉問天將$n交還給$N。\n",me,tb);
	message_vision(HIY + "醉問天說：希望還有機會為$N" + HIY + "服務，歡迎$N" + HIY + "的再度來臨!!\n" + NOR,me,tb);
	me->add("sky/"+arg,-1);
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

int do_list()
{
	string *obj;
	object me,ob;
	int i,j;
	me=this_player();
	ob=this_object();
	if(!me->query("sky"))
		return notify_fail("你目前目前並沒有在我這兒存放任何東西喔!!\n");
	obj=keys(me->query("sky"));

        printf("%s存放在我這的寶物如下：\n",me->name());
	for(i=0;i<sizeof(obj);i++)
	{
	if( me->query("sky/"+obj[i])==0 ) continue;
	printf(HIM + "【" + HIW + "%-28s" + HIM + "】" + NOR + "共有" + HIM + "【" + HIW + "%2d" + HIM + "】" + NOR + " 個。\n",to_chinese(obj[i])+"("+obj[i]+")",me->query("sky/"+obj[i]));
	}

	return 1;
}

