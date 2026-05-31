// hockshop.c by chun 1995.10.21

inherit ROOM;
inherit CHINESE_D;
inherit F_FINANCE;

mapping pawnob = ([ ]);
mapping pawnname = ([ ]);
mapping pawnvalue = ([ ]);
mapping pawnpath = ([ ]);
mapping pawntime = ([ ]);

void create()
{
	set("no_clean_up",1);
	setup();
}

void redeem_thing(string arg)
{
	map_delete( pawnob , arg );
	map_delete( pawnname , arg );
	map_delete( pawnvalue , arg );
	map_delete(pawnpath , arg );
	map_delete(pawntime , arg );
}

void init()
{
/*
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_redeem","redeem");
	add_action("do_list","list");
*/
    add_action("do_nowork","value");
    add_action("do_nowork","pawn");
    add_action("do_nowork","redeem");
    add_action("do_nowork","list");
}

int do_list(string arg)
{
	string	*pn;
	object	me=this_player();
	int i;

	if(!arg) arg = me->query("id");
	else if (!wizardp(me) && arg != me->query("id"))
	    return notify_fail("請輸入自己的id\n");
	pn = keys(pawnname);
	if(sizeof(pn) == 0)
		return notify_fail("喔！您沒在這兒典當物品。\n");
	printf("\t您典當在這兒的物品有：\n");
	for(i=0;i<sizeof(pn);i++)
	{
	  if( pawnname[pn[i]] == arg )
	    printf("\t\t%s\n",pawnob[pn[i]]);
	}
	return 1;
}

int do_value(string arg)
{
	object ob,*inv, me=this_player();
	int value;

	if( arg )
	{
	if( !(ob = present(arg, me)) )
		return notify_fail("你要拿什麼物品給當鋪估價﹖\n");

	if( ob->query("money_id") )
		return notify_fail("這是「錢」﹐你沒見過嗎﹖\n");
  if( ob->query("bad") )
    return notify_fail("這東西壞掉了，就不值錢了。\n");

	value = ob->query("value");
	if( !value ) printf("%s一文不值。\n", ob->query("name"));
	else 
		printf("%s價值%s。\n如果你要典當(pawn)﹐可以拿到%s。\n",
			ob->short(), cvalue(value),
			cvalue(value * 60 / 100));

	return 1;
}
else
{
	inv = all_inventory(me);
	if( !sizeof(inv) )
	 {
		return notify_fail( "目前你身上沒有任何東西可供估價。\n");
	}
	printf("你身上帶著這些東西：\n%s\n",
	implode(map_array(inv,"value_list",this_object()),"") );
	return 1;
}
}
int do_pawn(string arg)
{
	object ob, me=this_player();
	int value,trade_lv;
	string pob, pid, ppath, ptime;


	if(!trade_lv = me->query_skill("trade",1) )
	trade_lv = 1;
	if (trade_lv > 100) trade_lv = 100;

	if( !arg || !(ob = present(arg, me)) )
		return notify_fail("你要典當什麼物品﹖\n");

	if( ob->query("money_id") )	return notify_fail("你要當「錢」﹖\n");
  if( ob->query("bad")) return notify_fail("這東西壞了，不值錢啦！\n");

	if( ob->query_amount() )
	return notify_fail("這東西不能當\n");
	value = ob->query("value");
	if( !value ) return notify_fail("這樣東西不值錢。\n");
// 修改by avgirl,幫派eq不能當...00/9/26
if(ob->query("clan_name")) return notify_fail("我不收這種奇怪的東西。\n");

	if(me->query_skill("trade",1) ||
	me->query_skill("trade") < 100 )
	me->improve_skill("trade",(random(me->query_int())+
	random(me->query_per()) )/2 );
	pob = ob->short();
	pid = me->query("id");
	ppath = base_name(ob);
	ptime = me->query("mudage");
	destruct(ob);
	if (!ob) {
	  pawnob[arg] = pob;
	  pawnname[arg] = pid;
	  pawnvalue[arg] = value;
	  pawnpath[arg] = ppath;
	  pawntime[arg] = ptime;
 	  message_vision("$N把身上的"+pob + "拿出來典當了"
	    +cvalue(value*trade_lv/100)+"\n",me );
	  me->pay_player(value *trade_lv/100);
	}
	else
 	  message_vision("當鋪老闆對$N說: 對不起喔, 今天休業。\n", me);

	return 1;
}

int do_redeem(string arg)
{
	object ob, me=this_player();
	int trade_lv,mage,recost;

if( !arg ) return notify_fail("你要贖回什麼?\n");
if( me->query("id") != pawnname[arg] )
	return notify_fail("咦？這不是您當的吧！\n");
	if(!trade_lv = me->query_skill("trade",1))
	  trade_lv = 1;
	if (trade_lv > 100) trade_lv = 100;
	mage = me->query("mudage");
	recost = pawnvalue[arg]+pawnvalue[arg]*((100-trade_lv)/500)+
((mage-pawntime[arg])/3600);
if( me->can_afford(recost) )
{
	ob = new(pawnpath[arg]);
	tell_object(me,"這是您要贖回的"+ob->short()+"\n");
	me->pay_money(recost);
	ob->move(me);
	redeem_thing(arg);
	message_vision("$N用了"+cvalue(recost)+"贖回"+ob->short()+"\n", me );
	if(me->query_skill("trade",1) ||
	me->query_skill("trade") < 100 )
	me->improve_skill("trade",(random(me->query_int())+
	random(me->query_per())/2) );
	return 1;
}
else
{
	return notify_fail("你沒有足夠的錢贖回這樣物品,\n
	贖回這樣物品需要"+cvalue(recost)+"\n");
}
}
int do_nowork()
{
    message_vision("當鋪小弟說道: 當鋪倒了, 現在不受理任何業務了!!!\n",this_player());
    return 1;
}
