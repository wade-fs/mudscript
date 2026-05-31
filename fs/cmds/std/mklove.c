// 修正 by babe

#include <ansi.h>

inherit F_CLEAN_UP;

int main( object me, string arg )
{
        object obj, old_target;

        seteuid(getuid());
        if(!arg || !objectp(obj = present(lower_case(arg), environment(me))))
                return notify_fail("你想和誰上床﹖\n");
        arg = lower_case(arg);

        if( !obj->is_character() )
                return notify_fail("看清楚一點﹐那並不是生物。\n");

        if( me->query("gin",) < 140 )
                return notify_fail("精力不足會馬上風喔！\n");

        if( me->query("combat_exp") < 50000 )
                return notify_fail("你江湖歷練不足。\n");

        if( obj->is_fighting() || me->is_fighting() )
		return notify_fail( "邊戰鬥邊做愛, 你瘋了嗎?\n" );

        if( !living(obj) )
                return notify_fail(obj->name() + "已經無法做愛了。\n");

        if(obj==me) {
		if( me->query("gender")=="男性" ) {
			message_vision( HIM"$N迅速脫下褲子, 掏出熱呼呼的大肉棒, 熟練地打起槍來。\n"NOR, me );
		}
		else {
			message_vision( HIM"$N靦腆地脫下裙子, 拿出究極狂想按摩電擊棒, 開始熟練地抽插起來。\n"NOR, me );
		}
		me->add("gin",-140);
		me->apply_condition("sex_poison",0);
		me->start_busy(2);
		return 1;
	}
	else if( obj->query_temp("sex",1)) {
                 write( HIM"你將"+obj->name()+"溫柔的摟住, 開始一段溫柔的纏綿。\n"NOR );
                 tell_object( obj, HIM + me->name() + "將你摟住, 帶你踏上一個甜美刺激的旅程。\n"NOR );
                 message_vision( HIW + obj->name() + "和" + me->name() + "正在親熱, 不要打攪。\n"NOR, me );
                 me->add("gin",-70);
                 obj->add("gin",-70);
                 me->apply_condition("sex_poison",0);
                 obj->apply_condition("sex_poison",0);
                 me->start_busy(2);
                 obj->start_busy(2);
                 me->delete_temp("sex",1);
                 obj->delete_temp("sex",1);
                 return 1;
        }

        if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
                message_vision("\n$N對著$n說道﹕"
                        + RANK_D->query_self(me)
                        + me->name() + "﹐妄求與"
                        + RANK_D->query_respect(obj) + "共赴雲雨﹗\n\n", me, obj
);
                          me->set_temp("sex",1);
                tell_object(obj, YEL "如果你願意和對方上床﹐請你也對" + me->name
() + "("+(string)me->query("id")+")"+ "下一次 mklove 指令。\n" NOR);
                write(YEL "由於對方是由玩家控制的人物﹐你必須等對方同意才能和他上床。\n" NOR);
                return 1;
        }

        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : mklove <人物>
指令說明 :
           這個指令是為了令狂想這個泥巴的指令更為完整
       也是為了讓熱戀之中的愛侶有正當發洩的管道，不過
       有時後這個指令也許有別的用處喔！ :D~~~
HELP
    );
    return 1;
}

