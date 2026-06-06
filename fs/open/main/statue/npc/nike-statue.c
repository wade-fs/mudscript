inherit NPC;
#include <ansi.h>
void create()
{
        set_name("耐吉的雕像",({"nike statue","nike"}));
        set("long","狂想之神。狂想的玩家為了能瞻仰他，紀念他的德行，所以特別建立了此一雕像。\n你可以試著(pray id)也許\有奇妙的效果喔!!\n");
        set("title",HBBLU+HIW"ψ" + HIY + "七奇" + HIR + "秘針" + HIW + "ψ" + HIG + "傳人" + NOR);
        set("nickname",HIR + "沉睡了" + HIC + "百年" + HIY + "的" + HIM + "孤寂" + NOR);
        set("unit","尊");
        set("age",291);
        set("value",100);
        set("no_get",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_sac",1);
        set("no_auc",1);
        set("env/can_tell_wiz","YES");
        set("no_reset",1);
        set_weight(500000);
        setup();
}

init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
	object me=this_player();

	if( !me->query_temp("nike_pray_"+arg) )
	{
	call_out("greeting",2,me,arg);
	message_vision(HIW + "一陣光芒籠罩$N" + HIW + "的全身，光芒過後，已將$N" + HIW + "的祈禱傳送到大神的耳邊。\n" + NOR,me);
	me->set_temp("nike_pray_"+arg,1);
	}else{
	  if( me->query_temp("nike_pray_"+arg) < 2 )
	  {
	  message_vision(HIW + "已經傳達您的心意了，請耐心等候處理!!\n" + NOR,me);
	  me->add_temp("nike_pray_"+arg,1);
	  }else{
	  message_vision(HIR + "\n吼!!都說已經正在處理了還來煩，該賞你一記鐵鎚!!\n\n" + NOR,me);
	  command("hammer "+me->query("id") );
	  }
	}
        return 1;
}

void greeting(object ob,string arg)
{
        object me;
        me=this_player();
        command("tell "+arg+" "+me->query("name")+"("+me->query("id")+")傳送一份祝福的祈禱給您!!\n ");

}

