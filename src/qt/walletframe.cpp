/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
#include "walletframe.h"
#include "bitcoingui.h"
#include "walletstack.h"

#include <QHBoxLayout>
#include <QMessageBox>

WalletFrame::WalletFrame(BitcoinGUI *_gui) :
    QFrame(_gui)
{
    // Leave HBox hook for adding a list view later
    QHBoxLayout *walletFrameLayout = new QHBoxLayout(this);
    setContentsMargins(0,0,0,0);
    walletStack = new WalletStack(this);
    walletStack->setBitcoinGUI(_gui);
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(walletStack);
}

WalletFrame::~WalletFrame()
{
}

void WalletFrame::setClientModel(ClientModel *clientModel)
{
    if (clientModel)
        walletStack->setClientModel(clientModel);
}

bool WalletFrame::addWallet(const QString& name, WalletModel *walletModel)
{
    return walletStack->addWallet(name, walletModel);
}

bool WalletFrame::setCurrentWallet(const QString& name)
{
    // TODO: Check if valid name
    return walletStack->setCurrentWallet(name);
}

void WalletFrame::removeAllWallets()
{
    walletStack->removeAllWallets();
}

bool WalletFrame::handlePaymentRequest(const SendCoinsRecipient &recipient)
{
    return walletStack->handlePaymentRequest(recipient);
}

void WalletFrame::showOutOfSyncWarning(bool fShow)
{
    if (!walletStack)
        return;

    walletStack->showOutOfSyncWarning(fShow);
}

void WalletFrame::gotoOverviewPage()
{
    walletStack->gotoOverviewPage();
}

void WalletFrame::gotoHistoryPage()
{
    walletStack->gotoHistoryPage();
}

void WalletFrame::gotoAddressBookPage()
{
    walletStack->gotoAddressBookPage();
}

void WalletFrame::gotoReceiveCoinsPage()
{
    walletStack->gotoReceiveCoinsPage();
}

void WalletFrame::gotoSendCoinsPage(QString addr)
{
    walletStack->gotoSendCoinsPage(addr);
}

void WalletFrame::gotoSignMessageTab(QString addr)
{
    walletStack->gotoSignMessageTab(addr);
}

void WalletFrame::gotoVerifyMessageTab(QString addr)
{
    walletStack->gotoSignMessageTab(addr);
}

void WalletFrame::encryptWallet(bool status)
{
    walletStack->encryptWallet(status);
}

void WalletFrame::backupWallet()
{
    walletStack->backupWallet();
}

void WalletFrame::changePassphrase()
{
    walletStack->changePassphrase();
}

void WalletFrame::unlockWallet()
{
    walletStack->unlockWallet();
}

void WalletFrame::setEncryptionStatus()
{
    walletStack->setEncryptionStatus();
}
