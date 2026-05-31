// pklist.c
// 使用於pk大賽時,用來看共殺了幾人的指令 by Chan

#include <command.h>
inherit F_CLEAN_UP;
int main(object me)
{
 object *user;
 string desc = "";
 int i, sam = 0;
 user = users();
 desc += "    狂    想  　殺    戮    大    會    成    績    一    覽    表\n\n";
 for(i=0; i<sizeof(user); i++) {
  if( !wizardp(user[i]) ) {
        desc += sprintf("  %10s%6s共殺死:%-3d名玩家",
                        user[i]->name(), "("+user[i]->query("id")+")",
                        user[i]->query("pkgame"));
        if( sam % 2 == 1 ) desc += "\n";
        sam += 1;
    }
 }
 desc += "\n";
 me->start_more(desc);
 return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : pklist
指令說明 :
           這是用來觀看你在PK大賽時共殺了多少人的指令。
HELP);
        return 1;
}
