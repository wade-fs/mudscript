// Bellicosity_Change.c
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{
        int i;
        int be=me->query("bellicosity");
        int F=me->query("force"); 
        int k=me->query_kar();
        if( !arg ||  !sscanf(arg, "%d", i) )
             return notify_fail("指令格式﹕cmd bc <加減殺氣>\n");
  
         
        if( i > me->query("force") )
                return notify_fail("你的內力不夠。\n");
        if( i < k && i >= 0 )
                return notify_fail("你最少要升"+chinese_number(k)+"點。\n");
        if( i > k && i < 0 )
                return notify_fail("你最少要降"+chinese_number(k)+"點。\n");

        if( (i+be)/2 >  me->query("max_force") )
                return notify_fail("你放出的殺氣太多,將無法控制。\n");
        if( (i+be) < 0 )
                return notify_fail("你降太多殺氣了。\n");
        if( me->query_temp("BC")=="USED")
                return notify_fail("你正在運功\中。\n");
        if ( i >=0 ) {
        me->add("force",-i);
        } else { me->add("force",i); }
        message_vision(HIC"$N運起功\力企圖改變殺意。\n"NOR,me);
        me->start_call_out((:call_other, __FILE__, "bell_change",me,i:),1);
        me->set_temp("BC","USED");
        return 1;
}
void bell_change(object me,int i)
{
         int b=random(me->query_kar());
  //     if( random(me->query_kar()) + 3 > random(me->query_cor()) + random(me->query_str()) ){
  //          message_vision(YEL"$N的轉換失敗 內力流失了。\n"NOR,me); }
  //      else {
   
    if ( i >= 0 ) {
    me->add("bellicosity",i-b);
    message_vision(YEL"$N的殺氣提升約"+chinese_number(i)+"點。\n"NOR,me);
         }
    else { 
    me->add("bellicosity",i+b);
    message_vision(YEL"$N的殺氣下降約"+chinese_number(-i)+"點。\n"NOR,me);
        }
            
   // }
      me->delete_temp("BC","USED");
          return ;
}

int help(object me)
{
    write(@HELP
 
指令格式﹕ cmd bc <殺氣>?
 
說明﹕這個指令讓你可以用內力轉殺氣,但以最大基本內力兩倍為上限。
      加: cmd bc 10  加十點
      減: cmd bc -10 減十點
 
HELP
);
     return 1;
}
