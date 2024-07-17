package org.xtuml.bp.welcome.cheatsheets.library;
import org.eclipse.jface.action.Action;
import org.eclipse.jface.dialogs.InputDialog;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.cheatsheets.ICheatSheetAction;
import org.eclipse.ui.cheatsheets.ICheatSheetManager;
import org.xtuml.bp.core.common.NonRootModelElement;
import org.xtuml.bp.core.ui.RenameAction;
import org.xtuml.bp.ui.canvas.Cl_c;
import org.xtuml.bp.welcome.cheatsheets.utilities.CheatSheetsUtilities;

public class RenameCanvasElement extends Action implements ICheatSheetAction {

	@Override
	public void run(String[] params, ICheatSheetManager manager) {
		String projectName = params[0];
		String elementOoaType = params[1];
		String elementName = params[2];
		String indirectParent = params[3];
		String directParent = params[4];
		String containerPkg = params[5];
		NonRootModelElement element = CheatSheetsUtilities.findElement(projectName,containerPkg,elementOoaType,elementName, indirectParent, directParent);
		
		if (element != null) {
			String oldName = Cl_c.Getname(element);
			Shell sh = PlatformUI.getWorkbench().getDisplay().getActiveShell();
			InputDialog id = new InputDialog(sh, "Rename",
					"Enter the new name:", oldName, null);
			int result = id.open();
			if (result == InputDialog.OK) {
				String newName = id.getValue();
				// Run this in an async to make sure that the operation that
				// triggered
				// this action is completed. Otherwise this leads to problems
				// when the
				// icon of the item being renamed is clicked (i.e., which causes
				// the rename
				// text widget to lose focus and trigger this method).
				Runnable query = RenameAction.getRenameQuery(element,
						newName, oldName, false);
				sh.getDisplay().asyncExec(query);
			}
		}else {
			CheatSheetsUtilities.canNotFindElementReport(elementOoaType, elementName);
		}
	}

}
