inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int main(object me,string arg)
{
object target;
string st1;
int lolo;
lolo=me->query("poison");
message_vision(
"$N體內尚有"+lolo+"點的毒素。\n",me);
return 1;
}

int help(object me)
{
   write(@HELP

指令格式﹕cmd query

說明﹕這個指令可以讓你知道體內含有的毒素量。

HELP
   );
   return 1;
}

