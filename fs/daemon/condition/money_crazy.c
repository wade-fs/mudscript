#include <combat.h>
#include <ansi.h>
inherit F_FUNCTION;

int update_condition(object me, int duration)
{
        if( duration >= 1 )
        {
        int s1,c1,i1,s2,c2,p1,c3,k1,i,j;

          if( me->query_temp("money_change") == 3 )
          {
          i=random(8);
          s1=me->query_str();
          c1=me->query_cor();
          i1=me->query_int();
          s2=me->query_spi();
          c2=me->query_cps();
          p1=me->query_per();
          c3=me->query_con();
          k1=me->query_kar();
            switch(i)
            {
            case 0:
            j=random(s1)+1;
            break;
            case 1:
            j=random(c1)+1;
            break;
            case 2:
            j=random(i1)+1;
            break;
            case 3:
            j=random(s2)+1;
            break;
            case 4:
            j=random(c2)+1;
            break;
            case 5:
            j=random(p1)+1;
            break;
            case 6:
            j=random(c3)+1;
            break;
            default:
            j=random(k1)+1;
            }
          tell_object(me,HIW"奇異的能量漸漸流遍你的全身，只感覺到你的"HIR"狂邪靈勁"HIW"正不斷的增強中。\n"NOR);
          message("vision",HIW+me->name()+HIR"身上隱隱泛著絲絲的紅光，正不斷地提升著"HIW+me->name()+HIR"的勁力。\n"NOR,environment(me), me);
          function_improved("money_crazy",j);
          me->apply_condition("money_crazy",duration-1);
          }else{
          return 0;
          }
        }
        if( duration == 0 )
        return 0;
          
        return 1;
}
