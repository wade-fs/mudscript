// change by hzx
inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name(HIC + "救命靈丹" + NOR,({"standby-pill"}));
        set("long",
"據說這是天竺高僧用了一甲子加持過的奇石，大小有如姆指大.\n"+
"傳說只要誠心祈求" + HIW + "(pray)" + NOR + "的話，會有意想不到的結果!\n");
        set("unit", "顆");
        set("base_unit", "顆");
        set("value",0);
        set("price_unit","gem");
        set("base_weight", 50);
		set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_save",1);
        set_amount(1);
        setup();
}
void init()
{
        if( this_player()==environment() )
        {
                add_action("eat_pill", "pray");
        }       
}

int eat_pill(string arg)
{      
    object ob,me=this_player();
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
		if(me->query("t_standby")>=me->query("max_standby")) 
	    {
		message_vision(HIC + "你曾經擁有的替身總數已達上限，無法再增加。\n" + NOR,me);	
		return 0;
		}
		else
	    {
        if(me->query("standby")>1)
        {
         message_vision(HIC + "你已經長命百歲了。\n" + NOR,me);
         return 0;
        }
        me->add("standby", 1);
        message_vision(HIC + "$N對" + HIW + "天珠" + HIC + "祈求長命百歲後," + HIW + "天珠" + HIC + "射出一道" + HIY + "黃光" + HIC + "罩住了$N\n" + NOR,me); 
        log_file("eat_pill/standby_stone.o",sprintf("%s(%s)於%s用了靈氣天珠。\n",me->query("name"),me->query("id"),ctime(time())[0..18]));              
      add_amount(-1);
        return 1;
		}
}


