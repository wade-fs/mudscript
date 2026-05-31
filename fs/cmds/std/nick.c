// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string tmp;

  if (!arg) return notify_fail("你要替自己取什麼綽號﹖\n");
  tmp = remove_color (arg);
  if( strlen(tmp)> 20)
    return notify_fail ("你的綽號真像老太婆的裹腳布﹐想一個短一點的、響亮一點的。\n");

// 應該能取消綽號吧... edit by lys
	if (arg == "none") {
		me->delete("nickname");
		write ("你的綽號取消了.\n");
		return 1;
	}
	arg = trans_color(arg);

	me->set("nickname", arg + NOR);
	write("Ok.\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : nick <外號, 綽號>
指令說明 :
           這個指令可以讓你為自己取一個響亮的名號或頭銜﹐你如果希望在
         綽號中使用 ANSI 的控制字元改變顏色﹐可以用以下的控制字串﹕

普通色			加 HI - 高亮度	加 B 背景	加 HB 高亮度背景

$BLK$ - 黑色				$BBLK$ - 黑色
$RED$ - 紅色		$HIR$ - 亮紅色	$BRED$ - 紅色	$HBRED$ - 亮紅色
$GRN$ - 綠色		$HIG$ - 亮綠色	$BGRN$ - 綠色	$HBGRN$ - 亮綠色
$YEL$ - 土黃色		$HIY$ - 黃色	$BYEL$ - 土黃色	$HBYEL$ - 黃色
$BLU$ - 深藍色		$HIB$ - 藍色	$BBLU$ - 深藍色	$HBBLU$ - 藍色
$MAG$ - 淺紫色		$HIM$ - 粉紅色	$BMAG$ - 淺紫色	$HBMAG$ - 粉紅色
$CYN$ - 藍綠色		$HIC$ - 天青色	$BCYN$ - 藍綠色	$HBCYN$ - 天青色
$WHT$ - 淺灰色		$HIW$ - 白色	$BWHT$ - 淺灰色	$HBWHT$ - 白色
$NOR$ - 恢復正常顏色

其中系統自動會在字串尾端加一個 $NOR$。
HELP
        );
        return 1;
}
