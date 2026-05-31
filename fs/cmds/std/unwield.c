// unwield.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, *inv;
	string str;
	int i, count;

	if( !arg ) return notify_fail("你要脫掉什麼﹖\n");
        arg = lower_case(arg);
         if(arg=="all") {
    inv = all_inventory(me);
    for(count=0, i=0; i<sizeof(inv); i++) {
if(inv[i]->query_temp("focuskee")==1)
return notify_fail("武器被真氣纏住，不能放下！\n");
if(inv[i]->query_temp("evil-mblade")==1)
return notify_fail("武器被陰靈纏住，不能放下！\n");
	if( inv[i]->query("equipped") && inv[i]->query("skill_type") )
	    if( inv[i]->unequip() ) {
                if( me->is_fighting() && userp(me) ) me->start_busy(1);
		if( !stringp(str = inv[i]->query("unwield_msg")) )
                        str = "$N放下手中的$n。\n";
		message_vision(str, me, inv[i]);
	    }
    }
    write("Ok.\n");        
    return 1;
  }

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上沒有這樣東西。\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("你並沒有裝備這樣東西作為武器。\n");

	if(ob->query_temp("focuskee")==1)
		return notify_fail("你的手被一股真氣纏住﹐無法將他放下。\n");
 if(ob->query_temp("evil-mblade")==1)
return notify_fail("你的手被一股陰靈纏住﹐無法將他放下。\n");
	if( ob->unequip() ) {
		if( me->is_fighting() && userp(me) ) me->start_busy(1);
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : unwield <物品名>
指令說明 : 
           這個指令讓你放下手中的武器。
其他參考 :
           wield，remove，wear
HELP
    );
    return 1;
}
 
