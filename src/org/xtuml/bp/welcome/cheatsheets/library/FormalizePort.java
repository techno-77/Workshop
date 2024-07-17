package org.xtuml.bp.welcome.cheatsheets.library;
import org.eclipse.jface.action.Action;
import org.eclipse.jface.viewers.StructuredSelection;
import org.eclipse.ui.cheatsheets.ICheatSheetAction;
import org.eclipse.ui.cheatsheets.ICheatSheetManager;
import org.xtuml.bp.core.Provision_c;
import org.xtuml.bp.core.Requirement_c;
import org.xtuml.bp.core.ui.Selection;
import org.xtuml.bp.core.ui.actions.GenericPackageFormalizeOnC_PAction;
import org.xtuml.bp.core.ui.actions.GenericPackageFormalizeOnC_RAction;
import org.xtuml.bp.ui.canvas.Connector_c;
import org.xtuml.bp.ui.canvas.GraphicalElement_c;
import org.xtuml.bp.ui.canvas.Model_c;
import org.xtuml.bp.ui.graphics.editor.GraphicalEditor;
import org.xtuml.bp.welcome.cheatsheets.utilities.CheatSheetsUIUtilities;
import org.xtuml.bp.welcome.cheatsheets.utilities.CheatSheetsUtilities;

public class FormalizePort extends Action implements ICheatSheetAction {

	@Override
	public void run(String[] params, ICheatSheetManager manager) {
		if (params == null)
			return;
		String PortName = params[0];
		int PortType = Integer.valueOf(params[1]);
		GraphicalEditor activeEditor = (GraphicalEditor) CheatSheetsUIUtilities.getActiveEditor();
		
		Model_c model = activeEditor.getModel();
		Connector_c[] connectors = Connector_c.getManyGD_CONsOnR2(GraphicalElement_c.getManyGD_GEsOnR1(model));
		Connector_c[] destList = CheatSheetsUtilities.filterConnector(connectors,PortType);
		Connector_c requiredConnector = CheatSheetsUtilities.getDesiredConnector(destList,PortName);
		
		if ( requiredConnector==null){
			CheatSheetsUtilities.canNotFindElementReport(null, PortName);
		}
		GraphicalElement_c ge = GraphicalElement_c.getOneGD_GEOnR2(requiredConnector);
		Object represents = ge.getRepresents();
		Action a = new Action() {
		};
		if ( represents instanceof Provision_c){
			StructuredSelection sel = new StructuredSelection(represents);
			Selection.getInstance().setSelection(sel, true);
			GenericPackageFormalizeOnC_PAction formalizeProvision = new GenericPackageFormalizeOnC_PAction();
			formalizeProvision.run(a);
		} else if (represents instanceof Requirement_c){
			StructuredSelection sel = new StructuredSelection(represents);
			Selection.getInstance().setSelection(sel, true);
			GenericPackageFormalizeOnC_RAction formalizeRequirment = new GenericPackageFormalizeOnC_RAction();
			formalizeRequirment.run(a);
			}
		}
}
