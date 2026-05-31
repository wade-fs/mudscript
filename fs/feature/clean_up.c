// clean_up.c
// by Annihilator@ES2
#include <dbase.h>
int clean_up()
{

// int i;

	if(environment())
		return 1;
	else if(inherits(ROOM,this_object())) return 1;
	
	if( !clonep()  ) return 1;

	if( interactive(this_object()))
		return 1;

	// by babe
	// 若此物件已被其他物件所包含, 就不再重複 clean_up, 以節省時間
	// 請勿再 environment()->query("no_clean_up");
/* 除了房間之外，物件身上不會有人的
     foreach(object inv in all_inventory()){
                if(userp(inv)) return 1;
        }
*/
	destruct(this_object());

	return 0;
}
