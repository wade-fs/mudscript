 int max_value(object me,string kinds);         //me:誰 kinds:哪一種類

int max_value(object me,string kinds)
{
object *user;
int mmax,vmax,value,i;

        user=users();
        i=sizeof(user);
        vmax = 0;
        mmax = me->query(kinds);

        for(i-=1;i>=0;i--)
        {
                value=user[i]->query(kinds);
                if ( me!=user[i] && value > vmax )
                        vmax = value;
        }

        if( mmax >= vmax )
                return 0;
        return 1;
}
