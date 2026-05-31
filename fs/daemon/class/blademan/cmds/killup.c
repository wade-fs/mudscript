// ´£¤É±þ®ð by swy
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int main(object me, string arg)
{
        int i;
        int be=me->query("bellicosity");
        if( !arg ||  !sscanf(arg, "%d", i) )
        return notify_fail("«ü¥O®æ¦¡¡Rcmd killup <±þ®ðÂI¼Æ>\n");
        if(me->query_skill_mapped("force")=="fireforce")
        return notify_fail("¥u¦³¥Î¦Û¨­¤º¥\\¤~¯à´£¤É±þ®ð¡C\n");
if(be+i > me->query("max_force"))
 return notify_fail("§A©Ò­n´£¤Éªº±þ®ð¥[­ì±þ®ð¤w¶W¹L±zªº¤º¤O¤F¡C\n");
        if( i*2 > me->query("force") )
        return notify_fail("§Aªº¤º¤O¤£¨¬¥HÀ£¨î±þ®ð¡C\n");
        if( i <= 0 )
        return notify_fail("§A³Ì¤Ö­n´£¤É¤@ÂI¡C\n");
        if( me->query_temp("killup")==1 )
        return notify_fail("§A¥¿¦b¹B¥\\¤¤¡C\n");
        me->add("force",-i);
        message_vision(HIC"$N¹B°_¦Û¨­¤º¥\\¥ø¹Ï´£¤É±þ®ð¡C\n"NOR,me);
        me->start_call_out((:call_other, __FILE__, "bell_change",me,i:),2);
        me->set_temp("killup",1);
        return 1;
}
void bell_change(object me,int i)
{
    me->add("bellicosity",i);
    message_vision(YEL"$Nªº±þ®ð´£¤É¤F"+chinese_number(i)+"ÂI¡C\n"NOR,me);
    me->delete_temp("killup");
    return ;
}

int help(object me)
{
    write(@HELP
 
«ü¥O®æ¦¡¡R cmd killup <±þ®ð­È>ð>
 
»¡©ú¡R³o­Ó«ü¥OÅý§A¥i¥H¥Î¤º¤OÂà±þ®ð,¦ý¤W­­¬°±zªº¤º¤O³Ì¤j­È¡C
      ¨Ò: cmd killup 10  ¥[¤QÂI
 
HELP
);
     return 1;
}
