#include "tree.h"

int main() {
    /* KAMUS LOKAL */
    BinTree p, p1left, p1right, p2left, p2right;
    int X, Y;
    boolean Kiri;
    char ans;
    /* ALGORITMA */
    // p1left = newTreeNode(2);
    p1right = newTreeNode(3);

    p2left = newTreeNode(4);
    p2right = newTreeNode(5);

    MakeTree(2, p2left, p2right, &p1left);
    MakeTree(1, p1left, p1right, &p);
    printf("Tree yang terbentuk:\n");
    printPreOrder(p);
    printf("\n\n");

    printf("Jumlah elemen p: %d\n", NbElmtTree(p));
    printf("Level X = 2: %d\n", level(p, 2));
    printf("Depth: %d\n\n", depth(p));
    printf("Search X = 1: %d\n", searchTreeNode(p, 1));
    printf("Search X = 9: %d\n\n", searchTreeNode(p, 9));

    printf("isLeaf X = 1: %d\n", isLeaf(p, 1));
    printf("isLeaf X = 3: %d\n", isLeaf(p, 3));

    printf("Info treeLoc X = 2: %d\n", ROOT(treeLocation(p, 2)));

    printf("Masukkan nilai info daun yang ingin ditambah: ");
    scanf("%d", &Y);
    printf("Masukkan tambah di sebelah nilai info daun mana?: ");
    scanf("%d", &X);
    printf("Ingin tambah daun di kiri? (Y/N): ");
    scanf(" %c", &ans);

    if (ans == 'Y') Kiri = true;
    else if (ans == 'N') Kiri = false;

    addLeaf(&p, X, Y, Kiri);
    printf("Tree setelah addLeaf:\n");
    printPreOrder(p);
    printf("\n");
    return 0;
}