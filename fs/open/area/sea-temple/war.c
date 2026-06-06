#include <ansi.h>

string mlong();

string mlong()
{
object me,ob;
int b;
string str;
	ob = this_object();
	me = this_player();

	b = ob->query("defence-build");

	if ( !b )
		return "
四周圍牆已經被破壞，水面上漂浮著破碎的殘骸。\n";

	b = b / 10 ;
	switch( b )
	{
		case 0:
			str = "
圍牆搖搖欲墬，高低起伏的海面漂浮著殘破不全的屍體，鮮血將
水面染上了淡淡的紅。\n";
			break;
		case 1:
			str = "
圍牆上出現一堆明顯的裂痕，海面的起伏落差約有一呎，波浪激
烈的搖擺\著，令人無法安穩的站立其中。\n";
			break;
		case 2:
			str = "
圍牆不斷發出喀咧的響聲，裂痕由中心向外輻射狀延伸，海面高
低起伏漸漸加大，拍打著牆壁的頻率緩緩增快。\n";
			break;
		case 3:
			str = "
堅固的圍牆偶而發出淡淡的亮光，波浪起伏一高一低，緩緩推向
四周。\n";
			break;
		case 4:
			str = "
堅固的圍牆發出淡淡的紅光，時亮時滅，一陣一陣的配合著波浪
一高一低的亮著。\n";
			break;
		case 5:
			str = "
堅固的圍牆發出淡淡的黃色光芒，亮光微弱的向四處放射，海面
上的波浪也因光芒的照射而顯的平靜。\n";
			break;
		case 6:
			str = "
圍牆發出黃色的光芒，一股微薄的保護膜覆蓋\在圍牆表面，緩緩
流動，與水面的微薄波動同步。\n";
			break;
		case 7:
			str = "
圍牆散發出耀眼的金黃色光芒，圍牆的表面有著一道結界，猶如
水流一般，不斷的在圍牆表面流動著，順著圍牆與水面的交接而下流
至水面表層，在水面表層留下淡淡的金黃色。\n";
			break;
		default:
			str = "沒這個設定，出錯了，請通知巫師。\n";
			break;
	}

	if( wizardp(me) )
		str = str + HIW + "(defence-build="+ob->query("defence-build")+")\n" + NOR;
return str;
}
