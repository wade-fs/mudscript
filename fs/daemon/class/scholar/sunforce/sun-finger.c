// handwriting.c by Onion
void create(){ seteuid(getuid()); }
int exert(object me,object target)
{
	string *WEAPON_NAME=({
"[0;34m一陽氣指[0m",
"[1;34m一陽氣指[0m",
"[0;36m一陽氣指[0m",
"[1;36m一陽氣指[0m",
"[1m一陽指氣[0m"
	});
	int damage = (me->query("force_factor")*me->query_skill("sunforce",1))/10;
        int force_cost = me->query("force_factor")*20;
	object ob;
	if( force_cost == 0 )
	  return notify_fail("至少要一成功\力喔。\n");
        if( me->query("force") < force_cost )
          return notify_fail("你的內力不夠。\n");
	if( present("sunforce finger",me) )
	  return notify_fail("你目前已經有另一束一陽氣指了。\n");
        if( !me->query("marks/sun-finger") )
          return notify_fail("你還沒學會喔。\n");
	if( damage == 0 )
	  damage=1;
        if( damage > 120)
          damage=120;
        ob=new(CLASS_D("scholar")+"/obj/sunfinger");
        ob->set_name(WEAPON_NAME[damage/30],({"sunforce finger","finger"}) );
	ob->set("weapon_prop/damage",damage);
	ob->move(me);
        message_vision("\n[1m$N面色凝重, 兩手解成大手印, 忽然大喝一聲, 一道指氣由指尖衝出, 燦爛無比。\n[0m\n",me);
	me->add("force",-force_cost);
        me->start_call_out( (: call_other, __FILE__, "do_vanish",ob,me :),20*60
);
        return 1;
}
void do_vanish(object ob,object me)
{
    if(!me) me=this_player();
    if(!me) me=previous_object();
    if(!me){
    if(ob) destruct(ob);
    return ;
    }
    if(!ob) return ;
	tell_object(me,"\n"+ob->query("name")+"慢慢的消逝於空氣中, 精氣回歸於大地。\n");
	destruct(ob);
}
