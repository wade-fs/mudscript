//turn_on_pearl-1.c kyao.c
//純粹訊息 by blazakira
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(duration >=1 && me->query_temp("sun-moon"))
		{
			message_vision("$N四周密密麻麻不斷地旋轉翻滾著一股神聖的『" + HIY + "昊玥罡\氣" + NOR + "』。\n",me);
//			me->apply_condition("sun-moon",duration-1); //不使用 因為當fun消失時 本判斷中就已經沒有query_temp("sun-moon")的存在
			return 1;
		}
	return 0;
}
