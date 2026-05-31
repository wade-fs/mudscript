// cset_title.c
// 給幫主設稱號的....           BY      Chan

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string tmp;
//要設一下沒幫派的人不能用吧!!!
// by bss
   if(!me->query("clan")) return 0;
  if(me->query("clan/rank") > 1)
    return notify_fail("你的階級不夠,不能使用此指令\n");
  if (!arg) return notify_fail("你要替自己取什麼稱號﹖\n");
//  tmp = remove_color (arg);
  if( strlen(arg) > 10)
  return notify_fail("你的稱號真像老太婆的裹腳布﹐想一個短一點的、響亮一點的。\n");
/*
// 應該能取消綽號吧... edit by lys
        if (arg == "none") {
                me->delete("nickname");
                write ("你的綽號取消了.\n");
                return 1; 
        }
*/

  //      arg = trans_color(arg);

        me->set("clan/title", arg );
        write("你的稱號設定完畢\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : cset_title <想要的稱號>
指令說明 :
           這個指令可以讓幫主為自己取一個漂亮的稱號。

HELP
        );
        return 1;
}
