inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("夜之封印石",({"night fon stone","stone"}));
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
	case "chen-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("chen")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("chen",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "gii-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("gii")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("gii",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "hun-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("hun")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("hun",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "kai-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("kai")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("kai",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "shen-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("shen")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("shen",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "shue-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("shue")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("shue",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "uiw-jade":
	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	if(!ob->query("uiw")==1 && (present(str,me)->query("specialitem")==1) )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
	ob->set("uiw",1);
	destruct(present(str,me));
	call_out("check",1,ob);
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

	if(ob->query("check") == 7 )
	{
	tell_object(users(),HIC"\n\n\t大地忽然劇烈地憾動了起來，在極遠處的一座山頂上落下了數道的閃電!!\n"NOR);
	tell_object(users(),HIC"\n\t遠處的閃電七彩繽紛，輕輕地劃過了天際，劃亮了整個天空!!\n"NOR);
	tell_object(users(),HIC"\n\t雷聲憾動了天地，飛鳥走獸們都慌忙的飛奔走散!!\n"NOR);
	call_out("msg1",10,ob);
	}
	return 1;
}

int msg1(object ob)
{
	object me=this_player();
	tell_object(users(),HIY"\n\n\t在天靈地界中的夜之封印石"HIY"因為"HIG+ me->query("name")+HIY"的努力而解開了!!\n"NOR);
	tell_object(users(),HIY"\n\t因為失去了神力護持的夜之封印石"HIY"開始劇烈抖動而開始崩散消逝!!\n"NOR);
	call_out("msg2",10,ob);
	return 1;
}

int msg2(object ob)
{
	object me=this_player(),room=environment(me);
	tell_object(users(),HIW"\n\n\t在天靈地界塵封已久的"HIM"「"NOR"夜天月星脛"NOR+HIM"」"NOR+HIW"從夜之封印石中得到了解放而現世了!!\n"NOR,ob);
	message_vision(HIW"\n\t七塊解開封印的星玉轉化為七束夜光，緩緩注入了"HIM"「"NOR"夜天月星脛"NOR+HIM"」"NOR+HIW"之中轉化為不可思議的力量!!\n",ob);
	message_vision(HIW"\n\t光茫消散之後"HIM"「"NOR"夜天月星脛"NOR+HIM"」"NOR+HIW"緩緩凝聚在$N"HIW"手中!!\n"NOR,me);
	new("/autoload/sky/night-legging")->move(me);
	write_file("/log/sky/nightfon",sprintf("%s(%s) 解開了「夜天月星脛」於 %s\n",me->name(1),me->query("id"),ctime(time())));
	room->set("no_reset",1);
	destruct(ob);
	return 1;
}
