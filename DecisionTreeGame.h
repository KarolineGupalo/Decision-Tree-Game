typedef struct DecisionTreeNode
{
    char* question; //Pointer auf die Frage im jeweiligen Knoten
    struct DecisionTreeNode* yes; //Pointer auf die "Ja"-Entscheidung
    struct DecisionTreeNode* no; //Pointer auf die "Nein"-Entscheidung
} DecisionTreeNode;

DecisionTreeNode* createNode(const char* question); //Diese Funktion erzeugt einen neuen Knoten im BST und damit auch den BST selbst. Nimmt String und gibt einen Pointer auf die Frage. 

void insertQuestion(DecisionTreeNode* root, const char* question, char answer); //Hier werde neue Nodes mit dem bereits bestehenden Node mittels einem Pointer für 'yes' oder 'no' verbunden.
void playGame(DecisionTreeNode* root); //Spieler kann durch den BST navigieren und beginnt beim root. Die Funktion wird, basierend auf der Auswahl der spielenden Person, traversiert, was zu unterschiedlichen Enden des Spiels führt.

void freeTree(DecisionTreeNode* root); //Befreit den für das Spiel reservierten Speicher.
