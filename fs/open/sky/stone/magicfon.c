inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY"幻"HIW"彩"HIY"封"HIW"印"HIY"石"NOR,({"magic fon stone","stone"}));
	set("long","一個封印著神兵利器的神秘石頭，上面有著數個大大小小不等的\n"
		  +"奇形怪洞，應該可以放入解開封印的物品，若想要得到封印的神\n"
		  +"兵，可以將你所得到的解封印的物品(insert)進去，就可以讓神\n"
		  +"兵神器重新現世。\n");
	set("unit","尊");
	set("value",100);
	set("no_get",1);
	set("no_sac",1);
	set("no_auc",1);
	set_weight(500000);
        setup();
}

void init()
{
	add_action("do_insert","insert");
}

int do_insert(string str)
{
	object ob=this_object(),me=this_player();

	if( !str )
	return 0;

	switch(str)
	{
	case "watermelon-doll"://1

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("watermelon")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("watermelon",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "tomato-doll"://2

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("tomato")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("tomato",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "strawberry-doll"://3

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("strawberry")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("strawberry",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "starfruit-doll"://4

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("starfruit")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("starfruit",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "pineapple-doll"://5

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("pineapple")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("pineapple",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "papaya-doll"://6

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("papaya")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("papaya",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "orange-doll"://7

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("orange")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("orange",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "muskmelon-doll"://8

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("muskmelon")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("muskmelon",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "mango-doll"://9

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("mango")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("mango",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "litchi-doll"://10

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("litchi")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("litchi",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "lemon-doll"://11

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("lemon")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("lemon",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "guava-doll"://12

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("guava")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("guava",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "grapes-doll"://13

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("grapes")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("grapes",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "cherry-doll"://14

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("cherry")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("cherry",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "banana-doll"://15

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("banana")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("banana",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "apple-doll"://16

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("apple")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("apple",1);
	destruct(present(str,me));
	call_out("check",3,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	default:

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	message_vision("$N似乎想放什麼東西，但卻找不到正確的位置放!!\n",me);
	break;
	}
	return 1;

}

int check(object ob)
{
	ob->add("check",1);

	if(ob->query("check") == 16 )
	{
	tell_object(users(),HIC"\n\n\t大地忽然劇烈地憾動了起來，在極遠處的一座山頂上落下了數道的閃電!!\n"NOR);
	tell_object(users(),HIC"\n\t遠處的閃電七彩繽紛，輕輕地劃過了天際，劃亮了整個天空!!\n"NOR);
	tell_object(users(),HIC"\n\t雷聲憾動了天地，飛鳥走獸們都慌忙的飛奔走散!!\n"NOR);
	call_out("msg1",5,ob);
	}
	return 1;
}

int msg1(object ob)
{
	object me=this_player();
	tell_object(users(),HIC"\n\n\t在天靈地界中的"HIY"幻"HIW"彩"HIY"封"HIW"印"HIY"石"HIC"因為"HIG+ me->query("name")+HIC"的努力而解開了!!\n"NOR);
	tell_object(users(),HIC"\n\t因為失去了神力護持的"HIY"幻"HIW"彩"HIY"封"HIW"印"HIY"石"HIC"開始劇烈抖動而開始崩散消逝!!\n"NOR);
	call_out("msg2",5,ob);
	return 1;
}

int msg2(object ob)
{
	object me=this_player(),room=environment(me);
	tell_object(users(),HIC"\n\n\t在天靈地界塵封已久的"HIM"「"HBBLU+HIC"幻彩靈戒"NOR+HIM"」"NOR+HIC"從"HIY"幻"HIW"彩"HIY"封"HIW"印"HIY"石"HIC"中得到了解放而現世了!!\n"NOR,ob);
	message_vision(HIW"\n\t十六個解開封印的娃娃轉化為十六道光茫，緩緩注入了"HIM"「"HBBLU+HIC"幻彩靈戒"NOR+HIM"」"NOR+HIW"之中轉化為不可思議的力量!!\n",ob);
	message_vision(HIW"\n\t光茫消散之後"HIM"「"HBBLU+HIC"幻彩靈戒"NOR+HIM"」"NOR+HIW"緩緩凝聚在$N手中!!\n"NOR,me);
	new("/autoload/sky/color_ring")->move(me);
	write_file("/log/sky/magicfon",sprintf("%s(%s) 解開了「幻彩靈戒」於 %s\n",me->name(1),me->query("id"),ctime(time())));
	room->set("no_reset",1);
	destruct(ob);
	return 1;
}
