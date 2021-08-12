#include <iostream>

using namespace std;

void perm1(char s[],int k) {
    static char res[10];
    static int flag[10] = {0};
    if(s[k] == '\0') {
        res[k] = '\0';
        cout << res << endl;
    }
    else{
        for(int i=0;s[i] != '\0';i++) {
            if(flag[i] == 0) {
                res[k] = s[i];
                flag[i] = 1;
                perm1(s,k+1);
                flag[i] = 0;
            }
        }
    }

}

void perm2(char s[], int l, int h) {
    int i;
    if(l == h)
        cout << s << endl;
    else {
        for(int i=l;i<=h;i++) {
            swap(s[i],s[l]);
            perm2(s,l+1,h);
            swap(s[i],s[l]);
        }
    }
}

int main() {
  char s[] = "abc";
  perm1(s,0);
  cout << endl;
  perm2(s,0,2);
}