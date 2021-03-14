#include <String>
#include <iostream>
#include <iomanip>
using namespace std;

void formula1(string, char, char, char, char, char, string, string, string);
void formula2(string, char, char, char, char, char, string, string, string);
void formula3(string, char, char, char, char, char, string, string, string, string);
void formula4(string, char, char, char, char, char, char, string, string, string, string);

int main(){
    
    char r = 'r';
    char q = 'q';
    char p = 'p';
    char f = '0';
    char t = '1';    
    char s = ' ';        
    string equiv = " is equivalent to ";
    string nequiv = " is NOT equivalent to ";
    string then = "->";
    string both = "<->";
    string eq1 = "Equivalence: p<->q === ((p+q) * (~p+~q))";
    string eq2 = "Equivalence: ~(p*q) === ~p+~q";
    string eq3 = "Equivalence: p<->q === ((p->q)*(q->p))";
    string eq4 = "Equivalence: (p->q)->r === p->(q->r)";  

    formula1(eq1, p, q, f, t,  s, both, equiv, nequiv);
    formula2(eq2, p, q, f, t, s, both, equiv, nequiv);
    formula3(eq3, p, q, f, t, s, then, both, equiv, nequiv);
    formula4(eq4, p, q, r, f, t, s, then, both, equiv, nequiv);

    return 0;
}


void formula1(string eq1, char p, char q, char f, char t, char s,  string both, string equiv, string nequiv){
    //p<->q === ((p+q) * (~p+~q))   
    string one = "(p<->q)";
    string two = "(p+q)";
    string three = "(~p+~q)";
    string four = "((p+q)*(~p+~q))";

    cout << eq1 << endl;
    cout << p << s << q << s << one << s << both << s << four << s << two << s << three << endl;
    cout << t << s << t << s << setw(7) << t << setw(4) << t << setw(16) << t << setw(6) << t << setw(8)<< f<< endl;
    cout << t << s << f << s << setw(7) << f << setw(4) << t << setw(16) << f << setw(6) << f << setw(8)<< f<< endl;
    cout << f << s << t << s << setw(7) << f << setw(4) << t << setw(16) << f << setw(6) << f << setw(8)<< f<< endl;
    cout << f << s << f << s << setw(7) << t << setw(4) << t << setw(16) << t << setw(6) << f << setw(8)<< t<< endl;
    cout << one << s << equiv << s << four << endl;
    cout << endl;
    cout << endl;
}
void formula2(string eq2, char p, char q, char f, char t, char s,string both, string equiv, string nequiv){
    //~(p*q) === ~p+~q"
    string one = "~(p*q)";
    string two = "(~p+~q)";
    
    cout << eq2 << endl;    
    cout << p << s << q << s << one << s << both << s << two << endl;
    cout << t << s << t << s << setw(6) << f << setw(4) << t << setw(8) << f << endl;
    cout << t << s << f << s << setw(6) << f << setw(4) << t << setw(8) << f << endl;
    cout << f << s << t << s << setw(6) << f << setw(4) << t << setw(8) << f << endl;
    cout << f << s << f << s << setw(6) << t << setw(4) << t << setw(8) << t << endl;
    cout << one << s << equiv << s << two << endl;
    cout << endl;
    cout << endl;
}
void formula3(string eq3, char p, char q, char f, char t, char s, string then, string both, string equiv, string nequiv){
    //p<->q === ((p->q)*(q->p))
    string one = "(p<->q)";
    string two = "(p->q)";
    string three = "(q->p)";
    string four = "((p->q)*(q->p))";

    cout << eq3 << endl;
    cout << p << s << q << s << one << s << both << s << four << s << two << s << three << endl;
    cout << t << s << t << setw(8) << t << setw(4) << t << setw(16) << t << setw(7) << t << setw(7) << t << endl;
    cout << t << s << f << setw(8) << f << setw(4) << t << setw(16) << f << setw(7) << f << setw(7) << t << endl;
    cout << f << s << t << setw(8) << f << setw(4) << t << setw(16) << f << setw(7) << t << setw(7) << f << endl;
    cout << f << s << f << setw(8) << t << setw(4) << t << setw(16) << t << setw(7) << t << setw(7) << t << endl;
    cout << one << s << nequiv << s << four << endl;
    cout << endl;
    cout << endl;
}
void formula4(string eq4, char p, char q, char r, char f, char t, char s, string then, string both, string equiv, string nequiv){
    //(p->q)->r === p->(q->r)
    string s1 = "((p->q)->r)";
    string s2 = "(p->(q->r))";
    string one = "(p->q)";
    string two = "(q->r)";

    cout << eq4 << endl;
    cout << p << s << q << s << r << s << one << s << s1 << s << both << s << s2 << s << two << endl;
    cout << t << s << t << s << t << setw(7) << t << setw(12) << t << setw(4) << t << setw(12) << t << setw(7) << t << endl;
    cout << t << s << t << s << f << setw(7) << t << setw(12) << f << setw(4) << t << setw(12) << f << setw(7) << f << endl;
    cout << t << s << f << s << t << setw(7) << f << setw(12) << t << setw(4) << t << setw(12) << t << setw(7) << t << endl;
    cout << t << s << f << s << f << setw(7) << f << setw(12) << t << setw(4) << t << setw(12) << t << setw(7) << t << endl;
    cout << f << s << t << s << t << setw(7) << t << setw(12) << t << setw(4) << t << setw(12) << t << setw(7) << t << endl;
    cout << f << s << t << s << f << setw(7) << t << setw(12) << f << setw(4) << f << setw(12) << t << setw(7) << f << endl;
    cout << f << s << f << s << t << setw(7) << t << setw(12) << t << setw(4) << t << setw(12) << t << setw(7) << t << endl;
    cout << f << s << f << s << f << setw(7) << t << setw(12) << f << setw(4) << f << setw(12) << t << setw(7) << t << endl;   
    cout << s1 << s << nequiv << s << s2 << endl;
}